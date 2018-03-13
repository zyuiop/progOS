//
// Created by Louis Vialar on 13.03.18.
//

#include <stdio.h>

#define N 10

typedef struct {
    unsigned int lines;
    unsigned int columns;
    double matrix[N][N];
} Matrice;

Matrice lire_matrice(void);

Matrice multiplication(const Matrice a, const Matrice b);

void affiche_matrice(const Matrice m);

int main(void) {
    printf("Matrice 1 : \n");
    Matrice mat1 = lire_matrice();
    printf("Matrice 2 : \n");
    Matrice mat2 = lire_matrice();
    printf("--------------------\n");


    if (mat2.lines != mat1.columns) {
        printf("Multiplication impossible !\n");
    } else {
        printf("Produit matriciel : \n");
        affiche_matrice(multiplication(mat1, mat2));
    }
}

Matrice lire_matrice(void) {
    Matrice matrice;
    do {
        printf("| Nombre de lignes [1-10] ? ");
        scanf("%d", &matrice.lines);
    } while (matrice.lines < 1 || matrice.lines > N);

    do {
        printf("| Nombre de colonnes [1-10] ? ");
        scanf("%d", &matrice.columns);
    } while (matrice.columns < 1 || matrice.columns > N);

    for (int y = 0; y < matrice.lines; ++y) {
        for (int x = 0; x < matrice.columns; ++x) {
            printf("| | M[%d,%d] = ", (y + 1), (x + 1));
            scanf("%lf", &matrice.matrix[y][x]);
        }
    }

    return matrice;
}

Matrice multiplication(const Matrice a, const Matrice b) {
    Matrice matrice;
    matrice.lines = a.lines;
    matrice.columns = b.columns;

    for (int y = 0; y < matrice.lines; ++y) {
        for (int x = 0; x < matrice.columns; ++x) {
            matrice.matrix[y][x] = 0;
            for (int i = 0; i < b.lines; ++i) {
                matrice.matrix[y][x] += a.matrix[y][i] * b.matrix[i][x];
            }
        }
    }

    return matrice;
}

void affiche_matrice(const Matrice m) {
    for (int y = 0; y < m.lines; ++y) {
        printf("[");
        for (int x = 0; x < m.columns; ++x) {
            printf("%lf", m.matrix[y][x]);

            if (x != m.columns - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}
