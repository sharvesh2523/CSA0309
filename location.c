#include <stdio.h>

int main() {
    int arr[50], n, key, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter element to find: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d\n", key, i);
            return 0;
        }
    }
    printf("Element not found!\n");
    return 0;
}
