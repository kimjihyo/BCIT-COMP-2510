#include <stdio.h>

int main() {
    int a = 5, b = 5;
    printf("%d\n", sscanf("123hello 456", "%d %d", &a, &b));
    printf("%d %d\n", a, b);
    return 0;
}