#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    int len = strlen(str);
    int visited[256] = {0};

    printf("Indices of repeated characters:\n");
    for(int i=0; i<len; i++) {
        if(visited[(int)str[i]] == 1) {
            printf("Character '%c' at index %d\n", str[i], i);
        }
        visited[(int)str[i]]++;
    }
    return 0;
}
