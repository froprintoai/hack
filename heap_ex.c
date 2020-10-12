#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *errorchecked_malloc(int size);

int main(int argc, char *argv[]) {
    char *char_ptr;
    int *int_ptr;
    int mem_size;

    if (argc < 2)
        mem_size = 50;
    else
        mem_size = atoi(argv[1]);
    
    char_ptr = (char*) errorchecked_malloc(mem_size);
    strcpy(char_ptr, "KOREHA HEAP NI COPY SAREMASU");

    int_ptr = (int*) errorchecked_malloc(12);
    *int_ptr = 31337;

    free(char_ptr);
    free(int_ptr);


}

void *errorchecked_malloc(int size) {
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "error : failed to allocate memory\n");
        exit(-1);
    }

    return ptr;
}