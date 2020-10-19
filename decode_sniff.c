#include <pcap.h>
#include "hacking.h"
#include "hacking-network.h"

void pcap_fatal(const char *, const char *);
void decode_ethernet(const u_char *);
void decode_ip(const u_char *);
u_int decode_tcp(const u_char *);

void caught_packet(u_char *, const struct pcap_pkthdr *, const u_char *);

int main() {
    struct pcap_pkthdr cap_header;
    const u_char *packet, *pkt_data;
    char errbuf[PCAP_ERRBUF_SIZE];
    char *device;

    pcap_t *pcap_handle;

    device = pcap_lookupdev(errbuf);
    if (device == NULL)
        pcap_fatal("pcap_lookupdev", errbuf);
    
    printf("sniffing %s\n", device);

    pcap_handle = pcap_open_live(device, 4096, 1, 0, errbuf);
    if (pcap_handle == NULL)
        pcap_fatal("pcap_open_live", errbuf);
    
    pcap_loop(pcap_handle, 3, caught_packet, NULL);

    pcap_close(pcap_handle);
}

void pcap_fatal(const char *failed_in, const char *errbuf) {
    printf("fatal error : %s : %s\n", failed_in, errbuf);
    exit(1);
}

void caught_packet(u_char *user_args, const struct pcap_pkthdr *cap_header, const u_char *packet) {
    int tcp_header_length, total_header_size, pkt_data_len;
    u_char *pkt_data;

    printf("==== received %d bytes packet ====\n", cap_header->len);

    decode_ethernet(packet);
    decode_ip(packet+ETHER_HDR_LEN);
    tcp_header_length = decode_tcp(packet+ETHER_HDR_LEN+sizeof(struct ip_hdr));
}

void decode_ethernet(const u_char *header_start) {
    int i;
    const struct ether_hdr *ethernet_header;

    ethernet_header = (const struct ether_hdr *)header_start;
    printf("[[ 2nd layer :: Ethernet Header]]\n");
    printf("[ src address : %02x", ethernet_header->ether_src_addr[0]);
    for (i = 1; i < ETHER_ADDR_LEN; i++)
        printf(":%0x2", ethernet_header->ether_src_addr[i]);
    printf("dest address : %02x", ethernet_header->ether_dest_addr[0]);
    for (i = 1; i < ETHER_ADDR_LEN; i++)
        printf(":%0x2", ethernet_header->ether_dest_addr[i]);
    printf("\ttype : %hu ]\n", ethernet_header->ether_type);
}

void decode_ip(const u_char *header_start) {
    const struct ip_hdr *ip_header;

    ip_header = (const struct ip_hdr *)header_start;

    printf("\t(( 3rd layer ::: IP Header))\n");
    printf("\t( src address : %s\t", inet_ntoa(*(struct in_addr*)(&(ip_header->ip_src_addr))));
    printf("dest address : %s)\n", inet_ntoa(*(struct in_addr*)(&(ip_header->ip_dest_addr))));
    printf("\t( type: %u\t", (u_int) ip_header->ip_type);
    printf("ID : %hu\tlength : %hu )\n", ntohs(ip_header->ip_id), ntohs(ip_header->ip_len));
}

u_int decode_tcp(const u_char *header_start) {
    u_int header_size;
    const struct tcp_hdr *tcp_header;

    tcp_header = (const struct tcp_hdr *)header_start;
    header_size = 4 * tcp_header->tcp_offset;

    printf("\t\t{{ 4th layer :::: TCP Header }}\n");
    printf("\t\t{ src port : %hu\t", ntohs(tcp_header->tcp_src_port));
    printf("dest port : %hu }\n", ntohs(tcp_header->tcp_dest_port));
    printf("\t\t{ Seq # : %u\t", ntohl(tcp_header->tcp_seq));
    printf("Ack # : %u }\n", ntohl(tcp_header->tcp_ack));
    printf("\t\t{ header size : %u\tflag: ", header_size);
    if (tcp_header->tcp_flags & TCP_FIN)
        printf("FIN ");
    if (tcp_header->tcp_flags & TCP_SYN)
        printf("SYN ");
    if (tcp_header->tcp_flags & TCP_RST)
        printf("RST ");
    if (tcp_header->tcp_flags & TCP_PUSH)
        printf("PUSH ");
    if (tcp_header->tcp_flags & TCP_ACK)
        printf("ACK ");
    if (tcp_header->tcp_flags & TCP_URG)
        printf("URG ");
    printf(" }\n");

    return header_size;
}