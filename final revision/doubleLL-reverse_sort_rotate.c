
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void insertAtEnd(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  struct Node* nodeOther = *head;
  while (nodeOther->next != NULL) {
    nodeOther = nodeOther->next;
  }
  nodeOther->next = newNode;
  newNode->prev = nodeOther;
}

void printList(struct Node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

struct Node* reverseK(struct Node* head, int k) {
  struct Node* current = head;
  struct Node* next = NULL;
  struct Node* newHead = NULL;
  int count = 0;
  while (current != NULL && count < k) {
    next = current->next;
    current->next = newHead;
    if (newHead != NULL) {
      newHead->prev = current;
    }
    newHead = current;
    current = next;
    count++;
  }
  if (next != NULL) {
    head->next = reverseK(next, k);
    head->next->prev = head;
  }
  return newHead;
}

struct Node* sortGroups(struct Node* head, int k) {
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;

    int count = 0;

    // Reverse the nodes in each group of k nodes
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Recursively sort the remaining nodes and attach them to the reversed group
    if (next != NULL) {
        head->next = sortGroups(next, k);
    }

    // Return the head of the reversed group
    return prev;
}

void rotateK(struct Node** headReference, int k) {
  if (k == 0) {
    return;
  }
  struct Node* current = (*headReference);
  int count = 1;
  while (count < k && current != NULL) {
    current = current->next;
    count++;
  }
  if (current == NULL) {
    return;
  }
  struct Node* kth_node = current;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = (*headReference);
  (*headReference)->prev = current;
  (*headReference) = kth_node->next;
  (*headReference)->prev = NULL;
  kth_node->next = NULL;
}

int main() {
  struct Node* head = NULL;
  int n, k, choice;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    int data;
    scanf("%d", &data);
    insertAtEnd(&head, data);
  }
  printf("1. Reverse \n2. Sort \n3. Rotate\n");
  printf("What would you like to do with your queue: ");
  scanf("%d", &choice);
  if (choice==1){
    printf("Enter the value of k: ");
    scanf("%d", &k);
    head = reverseK(head, k);
    printf("List after reversing elements in groups of %d: ", k  );
    printList(head);
  }
  if (choice==2){
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("Original list: ");
    printList(head);
    head= sortGroups(&head, k);
    printf("Sorted list: ");
    printList(head);
    }
  if (choice==3){
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("Original list: ");
    printList(head);
    printf("Rotated list: ");
    rotateK(&head, k);
    printList(head);
  }
  return 0;
}

