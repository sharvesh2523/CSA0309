#include <stdio.h>

int main() {
    int arr[50], n, key, i, found = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter %d reg nos: ", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter reg no to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Reg no %d found at position %d\n", key, i);
            found = 1;
            break;
        }
    }
    if (!found) printf("Reg no not found!\n");
    return 0;
}
