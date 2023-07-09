#include <stdio.h>
#include <stdlib.h>

// Definition of a BST node
struct node {
  int data;
  struct node* left;
  struct node* right;
};

// Function to create a new BST node
struct node* newNode(int data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a new node into the BST
struct node* insert(struct node* node, int data) {
  if (node == NULL) {
    return newNode(data);
  }
  if (data < node->data) {
    node->left = insert(node->left, data);
  } else if (data > node->data) {
    node->right = insert(node->right, data);
  }
  return node;
}

// Function to print all the nodes in the BST in the range K1 and K2
void printRange(struct node* node, int K1, int K2) {
  if (node == NULL) {
    return;
  }
  if (K1 < node->data) {
    printRange(node->left, K1, K2);
  }
  if (K1 <= node->data && K2 >= node->data) {
    printf("%d ", node->data);
  }
  if (K2 > node->data) {
    printRange(node->right, K1, K2);
  }
}

// Main function
int main() {
  struct node* root = NULL;
  int n, data, K1, K2;

  printf("Enter the number of nodes in the BST: ");
  scanf("%d", &n);

  printf("Enter the nodes of the BST:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &data);
    root = insert(root, data);
  }

  printf("Enter the range K1 and K2: ");
  scanf("%d %d", &K1, &K2);

  printf("Nodes in the BST in the range %d and %d are: ", K1, K2);
  printRange(root, K1, K2);

  return 0;
}
