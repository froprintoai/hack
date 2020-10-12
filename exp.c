#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void f(int x) {
    printf("%d\n", x);
}

int main(int argc, char *argv[]) {
    char s[8];
    strcpy(s, argv[1]);
    printf("%s\n", s);

    f(3);
}