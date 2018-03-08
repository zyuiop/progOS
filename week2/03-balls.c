#include <stdio.h>
#include <math.h>

//
// Created by zyuiop on 08/03/18.
//
int main(void) {
    int h0;
    double eps, h_fin;
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
        printf("Hauteur de fin ? (0 < h < h0) ");
        scanf("%lf", &h_fin);
        printf("\n");
    } while (h_fin <= 0 || h_fin >= h0);

    // Do the math now
    double v = 0, v1 = 0, h = h0;
    int nb_rebonds = 0;

    do {
        v = sqrt(2 * h * g);
        v1 = eps * v;
        h = (v1 * v1) / (2 * g);
        ++ nb_rebonds;
    } while (h > h_fin);

    printf("Nombre de rebonds : %d\n", nb_rebonds);

    return 0;
}
