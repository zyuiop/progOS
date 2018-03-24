//
// Created by Louis Vialar on 19.03.18.
//


#include <stdio.h>

int main(void) {
    FILE *f = fopen("data.dat", "r");

    if (f == NULL) {
        fprintf(stderr, "Erreur : impossible de lire dans le fichier data.dat");
    } else {
        int count = 0;
        do {
            char name[16] = "               "; // 15 whitespaces
            char numb[4] = "   ";
            int age = 0;
            fscanf(f, "%s\t%d\n", name, &age);
            sprintf(numb, "%d", age);

            int arrSize = 0;

            while (arrSize < 4 && numb[arrSize] != ' ') {
                arrSize++;
            }

            int offset = 3 - arrSize;
            if (offset > 0) {
                for (int i = 2; i >= 0; -- i) {
                    numb[i] = numb[i - offset];
                }

                for (int i = 0; i < offset; ++ i) {
                    numb[i] = ' ';
                }
            }

            printf("| %s | %s |", name, numb);
        } while (!feof(f));

        fclose(f);

        printf("\nC'est tout bon !");
    }
}