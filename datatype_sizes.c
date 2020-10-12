#include <stdio.h>

int main() {
    printf("int : %d bytes\n", sizeof(int));
    printf("short int : %d bytes\n", sizeof(short int));
    printf("long int : %d bytes\n", sizeof(long int));
    
    printf("*int : %d bytes\n", sizeof(int*));
}