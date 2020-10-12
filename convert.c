#include <stdio.h>

int main(int arg_count, char* arg_list[]) {
    int i, count;
    /*
    if (arg_count < 3) {
        printf("usage\n\t%s <message> <number>\n", arg_list[0]);
    } else {
        count = atoi(arg_list[2]);
        for (i = 0; i < count; i++) {
            printf("%d : %s\n", i, arg_list[1]);
        }
    }
    */

    count = atoi(arg_list[2]);
    for (i = 0; i < count; i++) {
        printf("%d : %s\n", i, arg_list[1]);
    }
}