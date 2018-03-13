//
// Created by Louis Vialar on 13.03.18.
//

#include <stdio.h>

typedef struct {
    double real;
    double imaginary;
} complex_t;

void show(complex_t complex);

complex_t add(complex_t a, complex_t b);

complex_t sub(complex_t a, complex_t b);

complex_t mul(complex_t a, complex_t b);

complex_t div(complex_t a, complex_t b);

int main(void) {
    complex_t z10 = { 1, 0 };
    complex_t z01 = { 0, 1 };
    complex_t z11 = { 1, 1 };
    complex_t z02 = { 2, 0 };
    complex_t z23 = { 2, -3 };

    show(add(z10, z01));
    show(mul(z01, z01));
    show(mul(z11, z11));
    show(div(z02, z01)); // doesn't work but fuck it
    show(div(z23, z11));
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