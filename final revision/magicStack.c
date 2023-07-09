#include <stdio.h>
#include <stdlib.h>

#define N 10
#define k 3

struct Queue {
    int front, rear, size;
    int* arr;
};

struct Stack {
    int top;
    struct Queue* arr;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->arr = (struct Queue*)malloc(N * sizeof(struct Queue));
    return stack;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = k;
    queue->arr = (int*)malloc(k * sizeof(int));
    return queue;
}

void enqueue(struct Queue* queue, int value) {
    if ((queue->front == 0 && queue->rear == queue->size - 1) || (queue->rear == (queue->front - 1) % (queue->size - 1))) {
        return;
    } else if (queue->front == -1) {
        queue->front = queue->rear = 0;
        queue->arr[queue->rear] = value;
    } else if (queue->rear == queue->size - 1 && queue->front != 0) {
        queue->rear = 0;
        queue->arr[queue->rear] = value;
    } else {
        queue->rear++;
        queue->arr[queue->rear] = value;
    }
}

int dequeue(struct Queue* queue) {
    if (queue->front == -1) {
        return -1;
    }

    int data = queue->arr[queue->front];
    queue->arr[queue->front] = -1;

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else if (queue->front == queue->size - 1) {
        queue->front = 0;
    } else {
        queue->front++;
    }

    return data;
}

void push(struct Stack* stack, int value) {
    int min_size = k + 1;
    int min_index = -1;

    for (int i = 0; i <= stack->top; i++) {
        if (stack->arr[i].rear - stack->arr[i].front < min_size) {
            min_size = stack->arr[i].rear - stack->arr[i].front;
            min_index = i;
        }
    }

    if (min_index == -1 || stack->arr[min_index].rear == stack->arr[min_index].size - 1) {
        stack->top++;
        stack->arr[stack->top] = *createQueue();
        min_index = stack->top;
    }

    enqueue(&stack->arr[min_index], value);
}

int pop(struct Stack* stack) {
    int max_size = -1;
    int max_index = -1;

    for (int i = 0; i <= stack->top; i++) {
        if (stack->arr[i].front != -1 && stack->arr[i].rear - stack->arr[i].front > max_size) {
            max_size = stack->arr[i].rear - stack->arr[i].front;
            max_index = i;
        }
    }

    if (max_index == -1) {
        return -1;
    }

    int data = dequeue(&stack->arr[max_index]);

    if (stack->arr[max_index].front == -1) {
        for (int i = max_index; i < stack->top; i++) {
            stack->arr[i] = stack->arr[i + 1];
        }
        stack->top--;
    }

    return data;
}

int search(struct Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        if (stack->arr[i].front == stack->arr[i].rear) {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}

void sortStack(struct Stack* stack) {
    int temp[N * k];
    int index = 0;

    for (int i = 0; i <= stack->top; i++) {
        for (int j = stack->arr[i].front; j <= stack->arr[i].rear; j++) {
            temp[index++] = stack->arr[i].arr[j];
        }
    }

    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (temp[i] < temp[j]) {
                int temp2 = temp[i];
                temp[i] = temp[j];
                temp[j] = temp2;
            }
        }
    }

    index = 0;

    for (int i = stack->top; i >= 0; i--) {
        for (int j = stack->arr[i].rear; j >= stack->arr[i].front; j--) {
            stack->arr[i].arr[j] = temp[index++];
        }
    }
}

int main() {
    struct Stack* stack = createStack();

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(stack, value);
    }

    sortStack(stack);

    printf("Sorted stack from top to bottom: ");
    while (stack->top != -1) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    return 0;
}
