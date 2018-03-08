#include <stdio.h>

int demander_nombre(int min, int max);

int main(void) {
    int number = demander_nombre(10, 100);
    printf("Nombre entré : %d\n", number);
}

int demander_nombre(int min, int max) {
    int holder;
    do {
        printf("Entrez un nombre >= %d ", min);
        if (max > min) {
            printf("et < %d ", max);
        }

        scanf("%d", &holder);
    } while ((holder >= max && max > min) || holder < min);
    return holder;
}