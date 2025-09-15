#include <stdio.h>
#include <limits.h>

int reverseInt(int x) {
    long rev = 0;
    while (x != 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    if (rev > INT_MAX || rev < INT_MIN) return 0; // overflow check
    return (int)rev;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Reversed: %d\n", reverseInt(n));
    return 0;
}
