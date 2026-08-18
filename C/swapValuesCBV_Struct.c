#include <stdio.h>

struct swapValues {
    int a;
    int b;
};

struct swapValues swap(int x, int y) {
    struct swapValues result;
    result.a = y;
    result.b = x;
    return result;
}

int main(void) {
    int a, b;
    printf("Enter the value of the first number: a = ");
    scanf("%d", &a);
    printf("Enter the value of the second number: b = ");
    scanf("%d", &b);

    printf("Before swap: a = %d, b = %d\n", a, b);

    struct swapValues swapped = swap(a, b);

    printf("After swap: a = %d, b = %d\n", swapped.a, swapped.b);

    return 0;
}