//
// Created by Louis Vialar on 13.03.18.
//

#include <stdio.h>

#define N_MAX 10

double scalaire(const double u[], const double v[], size_t taille);

void input_vector(int vector_n, double vector[], size_t taille);

int main(void) {
    double v1[N_MAX];
    double v2[N_MAX];
    size_t val = 0;

    do {
        printf("Indiquez la taille des vecteurs (entre 1 et 10 inclus) : ");
        scanf("%d", &val);
    } while (val < 1 || val > N_MAX);

    input_vector(1, v1, val);
    input_vector(2, v2, val);

    // Exemple : a = (5, 3, -1)   b = (2, 1, 2)    a.b = 11
    printf("Produit scalaire : %lf", scalaire(v1, v2, val));
}

void input_vector(int vector_n, double vector[], size_t taille) {
    printf("Saisie du vecteur %d :\n", vector_n);
    for (int i = 0; i < taille; ++i) {
        printf("  Composante %d : ", (i + 1));
        scanf("%lf", &vector[i]);
    }
}

double scalaire(const double u[], const double v[], size_t taille) {
    double scalar = 0;
    for (int i = 0; i < taille; ++ i) {
        scalar += u[i] * v[i];
    }
    return scalar;
}
