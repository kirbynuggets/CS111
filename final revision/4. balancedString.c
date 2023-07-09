#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 100
char stack[n];
int top = -1;

void push(char data) {
    if (top == n - 1) {
        printf("Stack is Overflowed!\n");
        return;
    }
    top++;
    stack[top] = data;
}

char pop() {
    if (top == -1) {
        printf("Stack is Empty!\n");
        return ' ';
    }
    char data = stack[top];
    top--;
    return data;
}

int matchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') {
        return 1;
    } else if (char1 == '[' && char2 == ']') {
        return 1;
    } else if (char1 == '{' && char2 == '}') {
        return 1;
    } else {
        return 0;
    }
}
int isBalanced(char* text) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == '(' || text[i] == '[' || text[i] == '{') {
            push(text[i]);
        } else if (text[i] == ')' || text[i] == ']' || text[i] == '}') {
            if (top == -1) {
                return 0;
            } else if (!matchingPair(pop(), text[i])) {
                return 0;
            }
        }
    }
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
   char text[n];
   printf("Input an expression in parentheses: ");
   scanf("%s", text);
   if (isBalanced(text)) {
       printf("The expression is balanced.\n");
   } else {
       printf("The expression is not balanced.\n");
   }
   return 0;

}
