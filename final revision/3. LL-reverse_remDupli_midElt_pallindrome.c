#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node* link;
};

//Reversing a linked list
struct Node* reverse(struct Node* first){
    struct Node* prev= NULL;
    struct Node* current= first;
    struct Node* next= NULL;

    while(current!=NULL){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    return prev;
    }


//Removing duplicates
int removeDuplicates(struct Node* first){
    struct Node* current= first;
    struct Node* other;

    if (current==NULL){
        return;
    }
    while(current->link!=NULL){
        if (current->data == current->link->data){
            other=current->link->link;
            free (current->link);
            current->link=other;
        }
        else{
            current=current->link;
        }
    }
}

//Finding mid element
void middleElement(struct Node* first){
    struct Node* slowPtr = first;
    struct Node* fastPtr = first;

    if (first!=NULL){
        while(fastPtr!=NULL && fastPtr->link!=NULL){
            fastPtr=fastPtr->link->link;
            slowPtr=slowPtr->link;
        }
        printf("The middle element is %d. \n", slowPtr->data);
    }
}


//Printing pallindrome
bool isPalindrome(struct Node* first) {
  struct Node* head = first;
  int count = 0;
  while (head != NULL) {
    count++;
    head = head->link;
  }

  int arr[count];
  head=first;
  int i = 0;
  while (head != NULL) {
    arr[i] = head->data;
    i++;
    head = head->link;
  }

  int j = i - 1;
  i = 0;
  while (i < j) {
    if (arr[i] != arr[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

int main(){

    //creating an empty Linkedlist
    struct Node* first= NULL;

    //Reading data values from user and adding them to Linkedlist
    int n;
    printf("Enter the number of Nodes: ");
    scanf("%d", &n);

    for (int i=0;i<n;i++){
        int data;
        printf("Enter data for node %d: ", i+1);
        scanf ("%d", &data);

        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->link=NULL;

        if(first==NULL){
            first=newNode;
        }else{
        struct Node* current=first;
        while(current->link!=NULL){
            current=current->link;
        }
        current->link=newNode;
        }
    }
    //Traversing and printing values
    struct Node* current=first;
    while(current!=NULL){
        printf("%d ", current->data);
        current=current->link;
    }

    printf("\nReverse\n");

    //Reverse the linked list
    first=reverse(first);
    current = first;
    while(current!=NULL){
        printf("%d ", current->data);
        current=current->link;
    }

    printf("\n");

    //Removing duplicates
    removeDuplicates(first);

    //Printing Middle Element
    middleElement(first);

    printf("\n");

    //Pallindrome check
    if (isPalindrome(first)) {
        printf("The linked list is a palindrome.\n");
    }
    else {
        printf("The linked list is not a palindrome.\n");
    }

  return 0;
}

