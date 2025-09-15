#include <stdio.h>

int main() {
    int n, i;
    long long a = 0, b = 1, c, sum = 0;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sum += a;
        c = a + b;
        a = b;
        b = c;
    }

    printf("Sum of Fibonacci series up to %d terms: %lld\n", n, sum);
    return 0;
}
