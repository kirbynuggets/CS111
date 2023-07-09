
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 100

struct Stack {
    int top;
    char arr[n];
};


void push(struct Stack* stack, char c) {
    if (stack->top == n - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = c;
}


char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    char c = stack->arr[stack->top];
    stack->top--;
    return c;
}

// Function to check whether a string is a palindrome or not using a stack
int isPalindrome(char* str) {
    int len = strlen(str);
    struct Stack stack;
    stack.top = -1;
    for (int i = 0; i < len / 2; i++) {
        push(&stack, str[i]);
    }
    for (int i = (len + 1) / 2; i < len; i++) {
        if (pop(&stack) != str[i]) {
            return 0;
        }
    }
    return 1;
}


int main() {
    char str[n];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str)) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
    return 0;
}
