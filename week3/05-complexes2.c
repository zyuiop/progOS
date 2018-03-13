//
// Created by Louis Vialar on 13.03.18.
//

#include <stdio.h>
#include <math.h>

typedef struct {
    double real;
    double imaginary;
} complex_t;

typedef struct {
    complex_t sol1;
    complex_t sol2;
} poly2_solutions;

void show(complex_t complex);

void print_solutions(poly2_solutions solutions);

complex_t add(complex_t a, complex_t b);

complex_t sub(complex_t a, complex_t b);

complex_t mul(complex_t a, complex_t b);

complex_t div(complex_t a, complex_t b);

complex_t cplx_sqrt(complex_t x);

poly2_solutions solve_second_degree(complex_t b, complex_t c);


int main(void) {
    show(cplx_sqrt((complex_t) {-1, 0}));


    print_solutions(solve_second_degree((complex_t) {0, 0}, (complex_t) {1, 0}));
    print_solutions(solve_second_degree((complex_t) {3, -2}, (complex_t) {-5, 1}));
}

void show(complex_t complex) {
    printf("%lf + %lf i\n", complex.real, complex.imaginary);
}

complex_t add(complex_t a, complex_t b) {
    return (complex_t) { a.real + b.real, a.imaginary + b.imaginary };
}

complex_t sub(complex_t a, complex_t b) {
    return (complex_t) { a.real - b.real, a.imaginary - b.imaginary };
}

complex_t mul(complex_t a, complex_t b) {
    return (complex_t) { a.real * b.real - a.imaginary * b.imaginary, a.real * b.imaginary + a.imaginary * b.real };
}

complex_t div(complex_t a, complex_t b) {
    double div = b.real * b.real + b.imaginary * b.imaginary;
    return (complex_t) { (a.real * b.real + a.imaginary * b.imaginary) / div, (a.imaginary * b.real - a.real * b.imaginary) / div };
}

complex_t cplx_sqrt(complex_t x) {
    double real = sqrt((sqrt(x.real * x.real + x.imaginary * x.imaginary) + x.real) / 2.0);
    double imagin = sqrt((sqrt(x.real * x.real + x.imaginary * x.imaginary) - x.real) / 2.0);

    if (x.imaginary < 0)
        imagin = -imagin;

    return (complex_t) { real, imagin };
}

poly2_solutions solve_second_degree(complex_t b, complex_t c) {
    complex_t delta = sub(mul(b, b), mul((complex_t) {4, 0}, c));

    return (poly2_solutions) {
            div(sub(sub((complex_t) {0, 0}, b), cplx_sqrt(delta)), (complex_t) {2, 0}),
            div(add(sub((complex_t) {0, 0}, b), cplx_sqrt(delta)), (complex_t) {2, 0})
    };
}

void print_solutions(poly2_solutions solutions) {
    printf("z1 = ");
    show(solutions.sol1);
    printf("z2 = ");
    show(solutions.sol2);
}