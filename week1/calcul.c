#include <stdio.h>

int main() {
    double x, y;
    double a, b, c, d;

    x = 2;
    y = 4;

    a = x + y;
    b = x - y;
    c = x * y;
    d = x / y;

    printf("%f + %f = %f \n", x, y, a);
    printf("%f - %f = %f \n", x, y, b);
    printf("%f * %f = %f \n", x, y, c);
    printf("%f / %f = %f \n", x, y, d);
}