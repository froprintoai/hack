#include <stdio.h>
#include <string.h>

int main() {
    char message[20];
    int i, count;

    strcpy(message, "Hello, World!\n");
    
    printf("how many worlds?\n");
    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        printf("%3d : %s\n", i, message);
    }

    return 0;
}