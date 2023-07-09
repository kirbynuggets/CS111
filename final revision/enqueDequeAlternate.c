#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int* queue;
    int front;
    int rear;
    int size;
} CircularQueue;

CircularQueue* createCircularQueue(int size) {
    CircularQueue* cq = (CircularQueue*)malloc(sizeof(CircularQueue));
    cq->queue = (int*)malloc(size * sizeof(int));
    cq->front = -1;
    cq->rear = -1;
    cq->size = size;
    return cq;
}

int isEmpty(CircularQueue* cq) {
    return (cq->front == -1);
}

int isFull(CircularQueue* cq) {
    return ((cq->rear + 1) % cq->size == cq->front);
}

void enqueue(CircularQueue* cq, int element) {
    if (isFull(cq)) {
        printf("Circular Queue is full.\n");
        return;
    }
    if (isEmpty(cq))
        cq->front = 0;
    cq->rear = (cq->rear + 1) % cq->size;
    cq->queue[cq->rear] = element;
}

void dequeue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular Queue is empty.\n");
        return;
    }
    if (cq->front == cq->rear)
        cq->front = cq->rear = -1;
    else
        cq->front = (cq->front + 1) % cq->size;
}

int getFront(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular Queue is empty.\n");
        return -1;
    }
    return cq->queue[cq->front];
}

int getRear(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular Queue is empty.\n");
        return -1;
    }
    return cq->queue[cq->rear];
}

void printQueue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular Queue is empty.\n");
        return;
    }
    int i = cq->front;
    while (i != cq->rear) {
        printf("%d ", cq->queue[i]);
        i = (i + 1) % cq->size;
    }
    printf("%d\n", cq->queue[i]);
}

int main() {
    int numQueues;
    printf("Enter the total number of circular queues: ");
    scanf("%d", &numQueues);

    CircularQueue** queues = (CircularQueue*)malloc(numQueues * sizeof(CircularQueue));
    CircularQueue* newQueue = createCircularQueue(numQueues);

    for (int i = 0; i < numQueues; i++) {
        int k;
        printf("Enter the number of elements in queue %d: ", i + 1);
        scanf("%d", &k);

        queues[i] = createCircularQueue(k);

        for (int j = 1; j <= k; j++) {
            enqueue(queues[i], j);
        }

        while (queues[i]->front != queues[i]->rear) {

            dequeue(queues[i]);

            int skippedElement = getFront(queues[i]);
            dequeue(queues[i]);

            enqueue(queues[i], skippedElement);
        }



        enqueue(newQueue, getFront(queues[i]));

    }

    printf("\n");
    printQueue(newQueue);


    printf("%d %d\n", getFront(newQueue), getRear(newQueue));

    // Free memory allocated for circular queues
    for (int i = 0; i < numQueues; i++) {
        free(queues[i]->queue);
        free(queues[i]);
    }
    free(queues);

    return 0;
}

