/*
    Author: Jihyo Kim
    Date: 20190224

    COMP-2510 Procedural Programming Lab06
*/

#include <stdio.h>

/*
    Implement a function that finds the miminum & maximum of an array a of n integers.
    PRECONDITION: n >= 1
*/
void min_max(const int a[], size_t n, int *pmin, int *pmax) {
    size_t i;
    for (i = 0; i < n; i++) {
        if (a[i] < *pmin) {
            *pmin = a[i];
        }
        if (a[i] > *pmax) {
            *pmax = a[i];
        }
    }
}

/* 
    For the following 2 functions, you are not allowed to call any other function in your
    implementation.
*/

/*
    The num_digits function returns the number of digits in a non-negative integer
    when written in base 10.
    For example, num_digits(32768) returns 5 & num_digits(123456789) returns 9.
*/
unsigned num_digits(unsigned long n) {
    unsigned i = 0;
    while (n != 0) {
        n /= 10;
        i++;
    }
    return i;
}

/*
    We say that a non-negative integer is reversible if, in base 10, when the digits
    of the number are written in reverse oreder, it gives the same number as the original.
    For example, 3, 11, 121, 1221, 327686723 are all reversible, whereas 12, 327327 are not.
    Implement a function is_reversible that retuns 1 if n is reversible; otherwise, 
    it returns 0.
*/
int is_reversible(unsigned long n) {
    int reversed = 0;
    int original = n;
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return reversed == original;
}

int main() {
    printf("%d\n", num_digits(123));
    printf("%d\n", is_reversible(1211));
    return 0;
}