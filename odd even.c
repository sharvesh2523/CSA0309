#include <stdio.h>

int main() {
    int arr[50], n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Even numbers: ");
    for (i = 0; i < n; i++) if (arr[i] % 2 == 0) printf("%d ", arr[i]);

    printf("\nOdd numbers: ");
    for (i = 0; i < n; i++) if (arr[i] % 2 != 0) printf("%d ", arr[i]);

    return 0;
}
