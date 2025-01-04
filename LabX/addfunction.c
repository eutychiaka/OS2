#include <stdio.h>

void add(int *a, int *b, int *c, int *res) {
    *res = *a + *b + *c;
}

int main() {
    int x = 5, y = 10, z = 15, sum;
    add(&x, &y, &z, &sum);
    printf("Sum of %d, %d, and %d is: %d\n", x, y, z, sum);
    return 0;
}

