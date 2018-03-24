//
// Created by zyuiop on 24/03/18.
//

#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

int main(void) {
    int v1 = 10, v2 = 50;

    printf("Before: v1=%d, v2=%d\n", v1, v2);
    swap(&v1, &v2);
    printf("After: v1=%d, v2=%d\n", v1, v2);
}