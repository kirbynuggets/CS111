#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    // Function to create a new node and initialize its values
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = data; // Assign the given data to the node
    newNode->left = NULL; // Set the left child pointer to NULL
    newNode->right = NULL; // Set the right child pointer to NULL
    return newNode; // Return the newly created node
}

void zigzagTraversal(Node* root) {
    // Function to perform zigzag traversal of a binary tree
    if (root == NULL)
        return;

    Node* currentLevel[100]; // Array to store nodes of the current level
    int currentLevelSize = 0; // Variable to keep track of the number of nodes in the current level

    Node* nextLevel[100]; // Array to store nodes of the next level
    int nextLevelSize = 0; // Variable to keep track of the number of nodes in the next level

    int leftToRight = 1; // Variable to determine the traversal direction (left to right or right to left)

    currentLevel[currentLevelSize++] = root; // Start with the root node in the current level

    while (currentLevelSize > 0) {
        Node* node = currentLevel[--currentLevelSize]; // Get the last node from the current level

        printf("%d ", node->data); // Print the data of the current node

        if (leftToRight) {
            // If the traversal direction is left to right, process the left child first and then the right child
            if (node->left)
                nextLevel[nextLevelSize++] = node->left; // Add the left child to the next level array
            if (node->right)
                nextLevel[nextLevelSize++] = node->right; // Add the right child to the next level array
        } else {
            // If the traversal direction is right to left, process the right child first and then the left child
            if (node->right)
                nextLevel[nextLevelSize++] = node->right; // Add the right child to the next level array
            if (node->left)
                nextLevel[nextLevelSize++] = node->left; // Add the left child to the next level array
        }

        // Check if all nodes in the current level have been processed
        if (currentLevelSize == 0) {
            // Copy the nodes from the next level array to the current level array
            for (int i = 0; i < nextLevelSize; i++) {
                currentLevel[i] = nextLevel[i];
            }

            currentLevelSize = nextLevelSize; // Update the size of the current level
            nextLevelSize = 0; // Reset the size of the next level array

            leftToRight = !leftToRight; // Change the traversal direction for the next level
        }
    }
}

int main() {
    // Take user input for the binary tree
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the root node: ");
    scanf("%d", &root->data);
    root->left = NULL;
    root->right = NULL;
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* node = queue[front++];
        printf("Enter the left child of %d (or -1 if there is no left child): ", node->data);
        int leftData;
        scanf("%d", &leftData);
        if (leftData != -1) {
            node->left = (struct Node*)malloc(sizeof(struct Node));
            node->left->data = leftData;
            node->left->left = NULL;
            node->left->right = NULL;
            queue[rear++] = node->left;
        } else {
            node->left = NULL;
        }
        printf("Enter the right child of %d (or -1 if there is no right child): ", node->data);
        int rightData;
        scanf("%d", &rightData);
        if (rightData != -1) {
            node->right = (struct Node*)malloc(sizeof(struct Node));
            node->right->data = rightData;
            node->right->left = NULL;
            node->right->right = NULL;
            queue[rear++] = node->right;
        } else {
            node->right = NULL;
        }
    }
    printf("Zigzag Traversal: ");
    zigzagTraversal(root); // Perform the zigzag traversal of the binary tree

    return 0;
}


