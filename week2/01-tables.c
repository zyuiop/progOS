//
// Created by zyuiop on 08/03/18.
//
#include <stdio.h>

void print_table(int table);

int main(void) {
    for (int table = 2; table <= 10; ++table) {
        print_table(table);
    }
}

void print_table(int table) {
    printf("Table de %d :\n", table);
    for (int i = 1; i <= 10; ++i) {
        printf("\t%d * %d = %d\n", i, table, (i * table));
    }
    printf("\n");
}
