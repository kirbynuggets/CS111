
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void underFlowCndn(){
    if (top == NULL){
        printf("The stack is empty. \n");
        return;
    }
    else
        printf("The stack is unempty. \n");
}

void push(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->link = top;
    top = newNode;
}

void display(){
    struct Node* temp;
    temp=top;
    if (top == NULL){
        printf("Underflow Condition");
    }
    else{
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp=temp->link;
        }
    }
}

void peek(){
    if (top == NULL){
        printf("Underflow condition.");
    }
    else{
        printf("peek element is %d ", top->data);
    }
}

void pop(){
    struct Node* newNode;
    if (top == NULL){
        printf("Underflow Condition");
    }
    else{
        top = top->link;
        free(newNode);
    }
}

int main(){
    int choice,x;
    int ch;
    do{
        printf("1. Underflow Condition \n2. Push \n3. Pop \n4. Peek \n5. Display \n6. Exit \n");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                underFlowCndn();
                break;
            case 2:
                printf("Enter elements to be pushed: ");
                scanf("%d", &x);
                push(x);
                break;
            case 3:
                pop();
                break;
            case 4:
                peek();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice \n");
        }
        printf("\nDo you want to continue? (0/1)");
        scanf("%d",&ch);}
        while(ch==1);
    }
