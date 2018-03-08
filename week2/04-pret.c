//
// Created by zyuiop on 08/03/18.
//

#include <stdio.h>

int main(void) {
    double s0, r, ir;

    do {
        printf("Montant prêté s0 ? (s0 >= 0) ");
        scanf("%lf", &s0);
        printf("\n");
    } while (s0 < 0);

    do {
        printf("Mensualités r ? (r > 0) ");
        scanf("%lf", &r);
        printf("\n");
    } while (r <= 0);

    do {
        printf("Taux d'intérêts ir ? (ir >= 0; ir < 1) ");
        scanf("%lf", &ir);
        printf("\n");
    } while (ir < 0 || ir >= 1);

    double remaining = s0;
    double interest = 0;
    int months = 0;

    do {
        interest += ir * remaining;
        remaining -= r;
        ++months;
    } while (remaining > 0);

    printf("Somme des intérêts encaissés : %lf (sur %d mois)", interest, months);
}