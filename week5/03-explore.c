//
// Created by zyuiop on 24/03/18.
//

#include <stdio.h>

typedef unsigned char byte;

void print_binary(byte b) {
    byte work;
    for (int i = 7; i >= 0; --i) {
        work = (b >> i) & 1;
        putchar(work ? '1' : '0');
    }
}

void print_byte(size_t size, byte b) {
    printf("%02zu : ", size);
    print_binary(b);
    printf("\t%3u", b);
    if (b >= 32 && b <= 126)
        printf("\t'%c'", b);
    printf("\n");
}

void dump_mem(byte const * b, size_t n) {
    printf("A partir de %#x : \n", b);
    for (size_t i = 0; i < n; ++i) {
        print_byte(i, b[i]);
    }
}

int main(void) {
    /*
     * Dans le main, définissez un int de valeur 80 (= 64 + 16), un autre valant -80, un double valant 0.5 et un autre
     * valant 0.1 ; puis utilisez votre fonction dump_mem pour regarder comment ces valeurs sont représentées en mémoire
     */

    int v1 = 80, v2 = -80;
    double d1 = 0.5, d2 = 0.1;

    dump_mem(&v1, sizeof(int));
    dump_mem(&v2, sizeof(int));
    dump_mem(&d1, sizeof(double));
    dump_mem(&d2, sizeof(double));
    dump_mem(&v1, sizeof(int) * 16 + sizeof(double) * 16); // volontary overflow
}