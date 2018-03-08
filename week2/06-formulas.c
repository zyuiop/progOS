//
// Created by zyuiop on 08/03/18.
//
#include <math.h>
#include <stdio.h>

void undefined_expression(int expr) {
    printf("Expression %d non définie\n", expr);
}

void expression_result(int expr, double result) {
    printf("Expression %d : %lf\n", expr, result);
}

int check_expression(int expr, int check) {
    if (check == 0) {
        undefined_expression(expr);
        return 0;
    }

    return 1;
}

int main(void) {
    double x;

    printf("Renseignez x reél : ");
    scanf("%lf", &x);

    if (check_expression(1, x != 0)) {
        expression_result(1, x / (1 - exp(x)));
    }

    if (check_expression(2, x > 0 && x != 1)) {
        expression_result(2, x * log(x) * exp(2 / (x - 1)));
    }

    if (check_expression(3, x != 2 && x * x >= 8 * x)) {
        expression_result(3, (-x - sqrt(x * x - 8 * x)) / (2 - x));
    }

    double in_log = (x * x) - (1 / x);
    if (check_expression(4, in_log > 0)) {
        double sin_part = sin(x) - (x / 20);
        sin_part *= log(sqrt(in_log));
        if (check_expression(4, sin_part >= 0)) {
            expression_result(4, sqrt(sin_part));
        }
    }
}
