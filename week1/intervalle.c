#include <stdio.h>

int main() {
    double val;
    printf("Entrez un réel : ");
    scanf("%lf", &val);

    if (val >= -1 && val < 1) {
        printf("\n%lf appartient à [-1; 1[", val);
    } else {
        printf("\n%lf n'appartient pas à [-1; 1[", val);
    }
}
