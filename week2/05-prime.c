//
// Created by zyuiop on 08/03/18.
//

#include <stdio.h>
#include <math.h>

int is_prime(int number, int* divisor) {
    if (number % 2 == 0) {
        if (number == 2) {
            return 1;
        } else {
            *divisor = 2;
            return 0;
        }
    } else {
        for (int i = 2; i < sqrt(number); ++i) {
            if (number % i == 0) {
                *divisor = i;
                return 0;
            }
        }

        return 1;
    }
}

int main(void) {
    int number;
    do {
        printf("Entier > 1 ? ");
        scanf("%d", &number);
        printf("\n");
    } while (number < 1);

    int divisor;
    if (is_prime(number, &divisor) == 0) {
        printf("Le nombre n'est pas premier car il est divisible par %d", divisor);
    } else {
        printf("Le nombre semble premier");
    }
}
