#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isEmpty(struct Node* root) {
    return root == NULL;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* delete(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int height(struct Node* root) {
    if (root == NULL) {
        return -1;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

int count(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return count(root->left) + count(root->right) + 1;
    }
}

struct Node* findMax(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Search\n");
        printf("7. Height\n");
        printf("8. Count\n");
        printf("9. Minimum\n");
        printf("10. Maximum\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data) == NULL) {
                    printf("Data not found.\n");
                } else {
                    printf("Data found.\n");
                }
                break;
            case 7:
                printf("Height: %d\n", height(root));
                break;
            case 8:
                printf("Count: %d\n", count(root));
                break;
            case 9:
                printf("Minimum: %d\n", findMin(root)->data);
                break;
            case 10:
                printf("Maximum: %d\n", findMax(root)->data);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
