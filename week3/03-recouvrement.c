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

int main(void) {
    Grille grille;

    int x = 0;
    int y = 0;

    do {

    } while (x >= 0 && y >= 0);

    /*
     * définissez une variable nommée grille, correspondant à un tableau de char, de taille fixe, à deux dimensions, avec DIM comme paramètre de taille pour chaque dimension (c'est-à-dire une grille carrée).
Le caractère '#' dans une case [i][j] de cette grille représente le fait qu'un (bout d')objet occupe la case de coordonnées (i, j) et le caractère '.' que la case est vide (utilisez des constantes).
Utilisez la fonction précédente pour remplir interactivement la grille, en demandant à l'utilisateur de spécifier la position, la taille et la direction des objets à placer.
Indiquez à chaque fois à l'utilisateur si l'élément a pu ou non être placé dans la grille.
Le remplissage se termine lorsque l'utilisateur entre une coordonnée strictement inférieure à 0.
Terminer alors en "dessinant" la grille : afficher un '.' si la case est vide et un '#' si la case est occupée.
     */
}

int remplitGrille(Grille grille, size_t ligne, size_t colonne, char direction, size_t longueur) {
    switch (direction) {
        case 'e':
            for (int i = 0; i < longueur; ++i) {
                if (grille[ligne][colonne + i] != EMPTY) {
                    return 0;
                }
            }

            for (int i = 0; i < longueur; ++i) {
                grille[ligne][colonne + i] = FILLED;
            }
            break;
        case 's':
            for (int i = 0; i < longueur; ++i) {
                if (grille[ligne + i][colonne] != EMPTY) {
                    return 0;
                }
            }

            for (int i = 0; i < longueur; ++i) {
                grille[ligne + i][colonne] = FILLED;
            }
            break;
        case 'w':
            return remplitGrille(grille, ligne, colonne - longueur, 'e', longueur);
        case 'n':
            return remplitGrille(grille, ligne - longueur, colonne, 's', longueur);
        default:
            return 0;
    }
}

void init_grid(Grille grille) {
    for (int i = 0; i < DIM; ++ i) {
        for (int j = 0; j < DIM; ++ j) {
            grille[i][j] = EMPTY;
        }
    }
}