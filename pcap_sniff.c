#include <pcap.h>
#include "hacking.h"

void pcap_fatal(const char *failed_in, const char *errbuf) {
    printf("fatal error : %s : %s\n", failed_in, errbuf);
    exit(1);
}

