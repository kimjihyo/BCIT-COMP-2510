/*
    Author: Jihyo Kim
    Date: 20190224

    COMP-2510 Procedural Programming Midterm For Burnaby Campus
*/
#include <stdio.h>

int array_max(int arr[], size_t n, int* pmaxcount) {
    size_t i;
    int max = arr[0];
    *pmaxcount = 1;
    for (i = 1; i < n; i++) {
        if (max == arr[i]) {
            (*pmaxcount)++;
        } else if (max < arr[i]) {
            max = arr[i];
            *pmaxcount = 1;
        }
    }
    return max;
}