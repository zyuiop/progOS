//
// Created by Louis Vialar on 13.03.18.
//

#define DIM 10
#define EMPTY '.'
#define FILLED '#'
#include <stdio.h>

typedef char Grille[DIM][DIM];

int remplitGrille(Grille grille, size_t ligne, size_t colonne, char direction, size_t longueur);

void init_grid(Grille grille);

void print_grid(Grille grille);

int main(void) {
    Grille grille;
    init_grid(grille);

    int x = 0;
    int y = 0;

    do {
        do {
            printf("Entrez coordonnées x [1-10] : ");
            scanf("%d", &x);
        } while (x > DIM);

        do {
            printf("Entrez coordonnées y [1-10] : ");
            scanf("%d", &y);
        } while (y > DIM);

        char chr;
        do {
            printf("Entrez direction (N,S,E,O) : ");
            scanf("%c", &chr);
        } while (chr != 'E' && chr != 'W' && chr != 'S' && chr != 'N');

        int taille;
        do {
            printf("Entrez taille : ");
            scanf("%d", &taille);
        } while (taille > DIM);

        if (remplitGrille(grille, y - 1, x - 1, chr, taille) == 1) {
            printf("Ok !\n");
        } else {
            printf("ça rentre pas...\n");
        }

        print_grid(grille);
    } while (x >= 0 && y >= 0);

    printf("Fini\n\n");

    print_grid(grille);
}

int remplitGrille(Grille grille, size_t ligne, size_t colonne, char direction, size_t longueur) {
    switch (direction) {
        case 'E':
            if (colonne + longueur > DIM) {
                return 0;
            }

            for (int i = 0; i < longueur; ++i) {
                if (grille[ligne][colonne + i] != EMPTY) {
                    return 0;
                }
            }

            for (int i = 0; i < longueur; ++i) {
                grille[ligne][colonne + i] = FILLED;
            }
            break;
        case 'S':
            if (ligne + longueur > DIM) {
                return 0;
            }

            for (int i = 0; i < longueur; ++i) {
                if (grille[ligne + i][colonne] != EMPTY) {
                    return 0;
                }
            }

            for (int i = 0; i < longueur; ++i) {
                grille[ligne + i][colonne] = FILLED;
            }
            break;
        case 'W':
            return remplitGrille(grille, ligne, colonne - longueur, 'e', longueur);
        case 'N':
            return remplitGrille(grille, ligne - longueur, colonne, 's', longueur);
        default:
            return 0;
    }

    return 1;
}

void init_grid(Grille grille) {
    for (int i = 0; i < DIM; ++ i) {
        for (int j = 0; j < DIM; ++ j) {
            grille[i][j] = EMPTY;
        }
    }
}

void print_grid(Grille grille) {
    for (int i = 0; i < DIM; ++ i) {
        for (int j = 0; j < DIM; ++ j) {
            printf("%c", grille[i][j]);
        }

        printf("\n");
    }
}