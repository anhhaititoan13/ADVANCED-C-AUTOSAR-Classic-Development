#include<stdio.h>
#include<stdint.h>

typedef struct Example{
    int8_t a  : 1;
    int8_t b  : 4;
}Example;

Example ex;

int main(){
    printf("size of struct: %zu\n", sizeof(ex));
}