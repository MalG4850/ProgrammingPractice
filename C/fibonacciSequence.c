#include <stdio.h>

void printFibonacci(int n) {
    unsigned long long t1 = 0;
    unsigned long long t2 = 1;
    unsigned long long nextTerm;

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return;
    }

    printf("Fibonacci Sequence: ");

    for (int i = 1; i <= n; ++i) {
        printf("%llu", t1);

        if (i < n) {
            printf(", ");
        }

        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

int main(void) {
    int count;
    printf("Enter the number of terms: ");
    if (scanf("%d", &count) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    printFibonacci(count);

    return 0;
}