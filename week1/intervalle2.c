#include <stdio.h>

int main() {
    // Dans cet exercice, nous autorisons uniquement l'utilisation des opérateurs relationnels < et ==.
    // Tous les opérateurs logiques ( &&, ||, etc) sont, par contre, autorisés.

    double val;
    printf("Entrez un réel : ");
    scanf("%lf", &val);

    printf("\n%lf ", val);

    if ((!(val < -10) && val < -2 || val == -2) || (!(val < 2) && val < 3) || (!(val < 0) && !(val == 0) && val < 1 || val == 1)) {
        printf("appartient");
    } else {
        printf("n'appartient pas");
    }
    printf(" à [2,3[ U ]0,1] U [-10,-2]");
}
