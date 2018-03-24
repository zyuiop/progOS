//
// Created by Louis Vialar on 19.03.18.
//

#include <stdio.h>

int main(void) {
    FILE *f = fopen("data.dat", "w");

    if (f == NULL) {
        fprintf(stderr, "Erreur : impossible d'écrire dans le fichier data.dat");
    } else {
        do {
            printf("Entrez un nom (CTRL+D pour terminer) : ");
            char name[128] = "";
            scanf("%s", name);

            if (feof(stdin)) {
                continue;
            }

            printf("âge : ");
            int age;
            if (scanf("%d", &age) != 1) {
                printf("Un nombre était demandé. Saisie annulée.\n");

                while (!feof(stdin) && !ferror(stdin) && getc(stdin) != '\n');

                continue;
            }

            // Text len
            fprintf(f, "%s\t%d\n", name, age);
            fflush(f);
        } while (!feof(stdin));

        fclose(f);

        printf("\nC'est tout bon !");
    }
}