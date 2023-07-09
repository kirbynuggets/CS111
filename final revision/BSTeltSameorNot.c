#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to traverse the BST in inorder fashion and store the elements in an array
void inorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
}

// Function to check whether two BSTs have the same elements or not
bool isSameBST(struct TreeNode* root1, struct TreeNode* root2) {
    int arr1[1000], arr2[1000];
    int index1 = 0, index2 = 0;

    // Traverse the first BST in inorder fashion and store the elements in arr1
    inorder(root1, arr1, &index1);

    // Traverse the second BST in inorder fashion and store the elements in arr2
    inorder(root2, arr2, &index2);

    // If the number of elements in both the BSTs is not the same, then they are not the same BSTs
    if (index1 != index2) {
        return false;
    }

    // Compare the elements of both the BSTs
    for (int i = 0; i < index1; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}

// Function to create a new node in the BST
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node in the BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to take input of a BST from the user
struct TreeNode* takeInput() {
    struct TreeNode* root = NULL;
    int n, val;
    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &n);
    printf("Enter the elements of the BST: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    return root;
}

int main() {
    // Take input of the first BST from the user
    printf("Enter the first BST:\n");
    struct TreeNode* root1 = takeInput();

    // Take input of the second BST from the user
    printf("Enter the second BST:\n");
    struct TreeNode* root2 = takeInput();

    if (isSameBST(root1, root2)) {
        printf("The two BSTs have the same elements.\n");
    } else {
        printf("The two BSTs do not have the same elements.\n");
    }

    return 0;
}
