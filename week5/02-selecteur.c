//
// Created by zyuiop on 24/03/18.
//

#include <stdio.h>

int main(void) {
    double v1 = 1, v2 = 2, v3 = 3;
    double* choice;

    int p;
    do {
        printf("Choisissez un nombre entre 1 et 3: ");
        scanf("%d", &p);
    } while (p < 1 || p > 3);

    switch (p) {
        case 1: choice = &v1; break;
        case 2: choice = &v2; break;
        case 3: choice = &v3;
    }

    printf("Variable correspondante: %lf, addr %ld", *choice, choice);
}