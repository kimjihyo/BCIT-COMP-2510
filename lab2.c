/*
    Author: Jihyo Kim
    Date: 20190224

    COMP-2510 Procedural Programming Lab02
*/

#include <stdio.h>

#define CHECK(X) printf("%s...%s\n", (X) ? "passed" : "failed", #X);

/*
    returns 1 if all corresponding elements of the two arrays a & b, each containing
    n integers, are equal; otherwise returns 0.
*/
int arr_equal(const int a[], const int b[], size_t n) {
    size_t i;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

/*
    if the integer x occurs in the array a of n integers, retuns rthe index of its
    last occurrence in the array; otherwise, returns -1 (as a size_t).
*/
size_t arr_find_last(const int a[], size_t n, int x) {
    size_t i, r = -1;
    for (i = 0; i < n; i++) {
        if (a[i] == x) {
            r = i;
        }
    }
    return r;
}

/*
    returns the number of occurrences of the integer x in the array a of n integers.
*/
size_t arr_count(const int a[], size_t n, int x) {
    size_t i, num = 0;
    for (i = 0; i < n; i++) {
        if (a[i] == x) {
            num++;
        }
    }
    return num;
}

/*
    returns the number of times the minimum value occurs in the array a of n integers.
    PRECONDITION: n >= 1
*/
size_t arr_count_min(const int a[], size_t n) {
    size_t i, num = 1;
    int min = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] == min) {
            num++;
        } else if (a[i] < min) {
            min = a[i];
            num = 1;
        }
    }
    return num;
}

int main() {
    int arr[] = {2, 3, 1, 5, 1, 2, 1};
    CHECK(arr_count_min(arr, 7) == 3);
    CHECK(arr_find_last(arr, 7, 2) == 5);
    CHECK(arr_count(arr, 7, 3) == 1);
    return 0;
}