#include <linux/if_ether.h>

int main() {
    printf("ethernet header struct size returned by sizeof : %d\n", sizeof(struct ethhdr));
    printf("ethernet header actual struct size : %d\n", ETH_HLEN);
    return 0;
}