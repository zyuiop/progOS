//
// Created by zyuiop on 08/03/18.
//

#include <stdio.h>
#include <math.h>

void prompt_and_read(char* val, double* ptr) {
    printf("%s ?", val);
    scanf("%lf", ptr);
}

int main(void) {
    printf("z³ + a2 * z² + a1 * z + a0\n");

    double a0, a1, a2;
    prompt_and_read("a0", &a0);
    prompt_and_read("a1", &a1);
    prompt_and_read("a2", &a2);

    printf("z^3 + %lf * z^2 + %lf * z + %lf = 0\n", a2, a1, a0);

    double q = (3 * a1 - a2 * a2) / 9.0;
    double r = (9 * a2 * a1 - 27 * a0 - 2 * pow(a2, 3)) / 54.0;
    double d = pow(q, 3) + pow(r, 2);

    double sub = - a2 / 3;
    if (d < 0) {
        double theta = acos(r / sqrt(pow(-q, 3)));
        double fact = 2 * sqrt(-q);
        printf("z1 = %lf\n", fact * cos(theta / 3) + sub);
        printf("z2 = %lf\n", fact * cos((theta + 2 * M_PI) / 3) + sub);
        printf("z3 = %lf\n", fact * cos((theta + 4 * M_PI) / 3) + sub);
    } else {
        double s = cbrt(r + sqrt(d));
        double t = cbrt(r - sqrt(d));

        printf("z1 = %lf\n", sub + s + t);
        if (d == 0 && s + t != 0) {
            printf("z2 = %lf\n", sub - (s + t) / 2);
        }
    }
}