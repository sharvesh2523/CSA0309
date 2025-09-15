#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if (!root) return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

int minValue(struct Node* node) {
    while (node->left) node = node->left;
    return node->data;
}

int maxValue(struct Node* node) {
    while (node->right) node = node->right;
    return node->data;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int key = 60;
    if (search(root, key))
        printf("%d found in BST\n", key);
    else
        printf("%d not found\n", key);

    printf("Min value = %d\n", minValue(root));
    printf("Max value = %d\n", maxValue(root));
    return 0;
}
