#include <stdio.h>

int main() {
    int a[50], b[50], c[100];
    int n1, n2, i, j = 0;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements: ");
    for (i = 0; i < n1; i++) scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements: ");
    for (i = 0; i < n2; i++) scanf("%d", &b[i]);

    for (i = 0; i < n1; i++) c[j++] = a[i];
    for (i = 0; i < n2; i++) c[j++] = b[i];

    printf("Merged array: ");
    for (i = 0; i < n1 + n2; i++) printf("%d ", c[i]);
    return 0;
}
