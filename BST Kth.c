#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if(root == NULL)
        return newNode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void kthMin(struct Node* root, int* k) {
    if(root == NULL)
        return;
    kthMin(root->left, k);
    (*k)--;
    if(*k == 0) {
        printf("kth minimum element is: %d\n", root->data);
        return;
    }
    kthMin(root->right, k);
}

int main() {
    struct Node* root = NULL;
    int n, val, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    kthMin(root, &k);
    return 0;
}
