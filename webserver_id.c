#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "hacking.h"
#include "hacking-network.h"

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host_info;
    struct sockaddr_in target_addr;
    unsigned char buffer[4096];

    if(argc < 2) {
        printf("usage : %s <hostname>\n", argv[0]);
        exit(1);
    }

    if ((host_info = gethostbyname(argv[1])) == NULL)
        fatal("NOT FOUND");
    
    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        fatal("failed to create a socket");
    
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(80);
    target_addr.sin_addr = *((struct in_addr *)host_info->h_addr);
    memset(&(target_addr.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(struct sockaddr)) == -1)
        fatal("failed to connect to the server");
    
    send_string(sockfd, "HEAD / HTTP/1.0\r\n\r\n");

    while(recv_line(sockfd, buffer)) {
        if (strncasecmp(buffer, "Server:", 7) == 0) {
            printf("%s 's web server info : %s\n", argv[1], buffer+8);
            exit(0);
        }
    }

    printf("Couldn't find a line containing Server\n");
    exit(1);

}