#include <stdio.h>
#include <stdint.h>

// struct Example {
//     int   b;   // 4 byte
//     char  a;   // 1 byte
//     // int   b;   // 4 byte
//     char  c;   // 1 byte
//     // padding (2 byte) ở cuối để đủ 4 byte
// };

struct Example {
    uint8_t  a; // 1 byte
    uint16_t b; // 2 byte
    uint32_t c; // 4 byte
};

int main() {
    printf("Size of struct Example: %zu\n", sizeof(struct Example));
    return 0;
}
