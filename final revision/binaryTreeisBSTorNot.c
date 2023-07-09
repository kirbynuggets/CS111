#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node with the given value.
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to check if a binary tree is a BST.
bool isBSTUtil(struct TreeNode* node, int min, int max) {
    if (node == NULL) {
        return true;
    }
    if (node->val < min || node->val > max) {
        return false;
    }
    return isBSTUtil(node->left, min, node->val - 1) && isBSTUtil(node->right, node->val + 1, max);
}

bool isBST(struct TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Function to build a binary tree from the given array.
struct TreeNode* buildTree(int* arr, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    struct TreeNode* root = newNode(arr[mid]);
    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);
    return root;
}

int main() {
    int n;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the values of the nodes in the binary tree: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct TreeNode* root = buildTree(arr, 0, n - 1);
    if (isBST(root)) {
        printf("The binary tree is a BST.\n");
    } else {
        printf("The binary tree is not a BST.\n");
    }
    return 0;
}
