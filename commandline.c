#include <stdio.h>

int main(int arg_count, char *arg_list[]) {
    int i;
    printf("Got %d args\n", arg_count);

    for (i = 0; i < arg_count; i++) {
        printf("\targ #%d : %s\n", i, arg_list[i]);
    }
}