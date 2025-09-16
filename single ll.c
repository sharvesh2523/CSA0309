#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL)
        *head = newNode;
    else {
        struct Node* temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int intersect(struct Node* head1, struct Node* head2) {
    while(head1 != NULL) {
        struct Node* temp = head2;
        while(temp != NULL) {
            if(head1->data == temp->data)
                return head1->data;
            temp = temp->next;
        }
        head1 = head1->next;
    }
    return -1;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    int n1, n2, val;
    printf("Enter size of first list: ");
    scanf("%d", &n1);
    printf("Enter elements:\n");
    for(int i=0; i<n1; i++) {
        scanf("%d", &val);
        append(&head1, val);
    }

    printf("Enter size of second list: ");
    scanf("%d", &n2);
    printf("Enter elements:\n");
    for(int i=0; i<n2; i++) {
        scanf("%d", &val);
        append(&head2, val);
    }

    int res = intersect(head1, head2);
    if(res != -1)
        printf("Intersection element: %d\n", res);
    else
        printf("No intersection element found.\n");

    return 0;
}
