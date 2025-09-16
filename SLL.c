#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

void append(struct Node** head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int isPalindrome(struct Node* head) {
    int size = 0;
    struct Node* temp = head;
    while(temp) {
        size++;
        temp = temp->next;
    }

    char arr[size], rev[size];
    temp = head;
    for(int i=0; i<size; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    for(int i=0; i<size; i++)
        rev[i] = arr[size - i - 1];

    for(int i=0; i<size; i++)
        if(arr[i] != rev[i])
            return 0;

    return 1;
}

int main() {
    struct Node* head = NULL;
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    for(int i=0; str[i]; i++)
        append(&head, str[i]);

    if(isPalindrome(head))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}
