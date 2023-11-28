#include <stdio.h>
#include <stdlib.h>

int main() {
    uint16_t var_sample_16 = 12;
    uint64_t var_sample_64 = 121212;
    size_t size_c = sizeof(char),
            size_s = sizeof(short),
            size_i = sizeof(int),
            size_l = sizeof(long),
            size_ll = sizeof(long long),
            size_unit16 = sizeof(uint16_t),
            size_unit16b = sizeof(var_sample_16),
            size_unit64 = sizeof(uint64_t),
            size_unit64b = sizeof(var_sample_64);
    struct aa { //24
        int x; // sizeof(int) = 4
        // Padding of 4 bytes
        double z; // sizeof(double) = 8
        short int y; // sizeof(short int) = 2
        // Padding of 6 bytes
    };
    struct bb { //16
        double z; // sizeof(double) = 8
        int x; // sizeof(int) = 4
        short int y; // sizeof(short int) = 2
        // Padding of 2 bytes
    };
    struct cc { //16
        uint8_t z; // sizeof(uint8_t) = 1
        uint16_t x; // sizeof = 2
        short int y; // sizeof(short int) = 2
        double zz; // sizeof(double) = 8
    };
    struct dd { //24
        uint8_t x; // sizeof(uint8_t) = 1
        double zz; // sizeof(double) = 8
        uint8_t z; // sizeof(uint8_t) = 1
    };
    struct ee { //24
        uint8_t x; // sizeof(uint8_t) = 1
        double zz; // sizeof(double) = 8
        uint8_t a; // sizeof(uint8_t) = 1
        uint8_t b; // sizeof(uint8_t) = 1
        uint8_t c; // sizeof(uint8_t) = 1
    };
    struct ff { //24
        uint8_t x; // sizeof(uint8_t) = 1
        double zz; // sizeof(double) = 8
        uint8_t a; // sizeof(uint8_t) = 1
        uint8_t b; // sizeof(uint8_t) = 1
    };
    struct gg { //
        uint8_t x; // sizeof(uint8_t) = 1
        uint8_t y; // sizeof(uint8_t) = 1
        uint8_t z; // sizeof(uint8_t) = 1
        uint16_t a; // sizeof(uint8_t) = 1
    };
    printf("Size of struct aa: %ld\n", sizeof(struct aa));
    printf("Size of struct bb: %ld\n", sizeof(struct bb));
    printf("Size of struct cc: %ld\n", sizeof(struct cc));
    printf("Size of struct dd: %ld\n", sizeof(struct dd));
    printf("Size of struct gg: %ld\n", sizeof(struct gg));

    struct ee ee_instance;
    struct ff ff_instance;
    printf("\nSize of struct ee: %ld\n", sizeof(struct ee));
    printf("ee arrangement: \n%p (%llu)\n%p (%llu)\n%p (%llu)\n%p (%llu)\n%p (%llu)\n\n",
           &ee_instance.x, ((uint64_t)&ee_instance.zz - (uint64_t)&ee_instance.x),
           &ee_instance.zz, ((uint64_t)&ee_instance.a - (uint64_t)&ee_instance.zz),
           &ee_instance.a, ((uint64_t)&ee_instance.b - (uint64_t)&ee_instance.a),
           &ee_instance.b, ((uint64_t)&ee_instance.c - (uint64_t)&ee_instance.b),
           &ee_instance.c, ((uint64_t)&ee_instance.x + sizeof(struct ee) - (uint64_t)&ee_instance.c));

    printf("Size of struct ff: %ld\n", sizeof(struct ff));
    printf("ff arrangement: \n%p (%llu)\n%p (%llu)\n%p (%llu)\n%p (%llu)\n\n",
           &ff_instance.x, ((uint64_t)&ff_instance.zz - (uint64_t)&ff_instance.x),
           &ff_instance.zz, ((uint64_t)&ff_instance.a - (uint64_t)&ff_instance.zz),
           &ff_instance.a, ((uint64_t)&ff_instance.b - (uint64_t)&ff_instance.a),
           &ff_instance.b, ((uint64_t)&ff_instance.x + sizeof(struct ff) - (uint64_t)&ff_instance.b));

    printf("char: %zu\n", size_c);
    printf("short: %zu\n", size_s);
    printf("int: %zu\n", size_i);
    printf("long: %zu\n", size_l);
    printf("long long: %zu\n", size_ll);
    printf("Obvious uint16_t: (%d) %zu, %zu\n", var_sample_16, size_unit16, size_unit16b);
    printf("Obvious uint64_t: (%llu) %zu, %zu\n", var_sample_64, size_unit64, size_unit64b);
}