#include <stdio.h>

int main() {
    printf("Quel age avez-vous ?\n");
    int age = 0;
    scanf("%d", &age);

    printf("Cool, on dirait que tu as %d ans\n", age);
    return 0;
}