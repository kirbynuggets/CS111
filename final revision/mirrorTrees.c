#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int areMirrors(struct node* a, struct node* b) {
    if (a == NULL && b == NULL) {
        return 1;
    }
    if (a == NULL || b == NULL) {
        return 0;
    }
    return (a->data == b->data) &&
           areMirrors(a->left, b->right) &&
           areMirrors(a->right, b->left);
}

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

struct node* createTree() {
    struct node* root = NULL;
    int data;
    printf("Enter the data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    root = newNode(data);
    printf("Enter the left child of %d:\n", data);
    root->left = createTree();
    printf("Enter the right child of %d:\n", data);
    root->right = createTree();
    return root;
}

int main() {
    struct node* a = NULL;
    struct node* b = NULL;

    printf("Enter the elements of tree a:\n");
    a = createTree();

    printf("Enter the elements of tree b:\n");
    b = createTree();

    if (areMirrors(a, b)) {
        printf("The trees are mirrors of each other.\n");
    } else {
        printf("The trees are not mirrors of each other.\n");
    }

    return 0;
}
