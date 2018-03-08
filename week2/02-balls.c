#include <stdio.h>
#include <math.h>

//
// Created by zyuiop on 08/03/18.
//
int main(void) {
    int h0, nbr;
    double eps;
    const double g = 9.81;

    do {
        printf("Hauteur initiale ? (>= 0) ");
        scanf("%d", &h0);
        printf("\n");
    } while (h0 < 0);

    do {
        printf("Coefficient de rebond ? (0 <= eps < 1) ");
        scanf("%lf", &eps);
        printf("\n");
    } while (eps < 0 || eps >= 1);

    do {
        printf("Nombre de rebonds ? (>= 0) ");
        scanf("%d", &nbr);
        printf("\n");
    } while (nbr < 0);

    // Do the math now
    double v = 0, v1 = 0, h = h0;

    for (int i = 0; i < nbr; ++i) {
        v = sqrt(2 * h * g);
        v1 = eps * v;
        h = (v1 * v1) / (2 * g);
    }

    printf("Au %dème rebond la hauteur sera de %lf m\n", nbr, h);

    return 0;
}
