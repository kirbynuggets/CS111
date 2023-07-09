
#include <stdio.h>
#include <stdlib.h>

#define maxHeapSize 100

typedef struct {
    int id;
    char name[50];
    int priority;
} Patient;

Patient heap[maxHeapSize];
int heapSize = 0;

void swap(Patient *a, Patient *b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i) {
    if (i && heap[i].priority < heap[(i - 1) / 2].priority) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        heapifyUp((i - 1) / 2);
    }
}

void heapifyDown(int i) {
    int child = 2 * i + 1;
    if (child < heapSize - 1 && heap[child].priority > heap[child + 1].priority) {
        child++;
    }
    if (child < heapSize && heap[i].priority > heap[child].priority) {
        swap(&heap[i], &heap[child]);
        heapifyDown(child);
    }
}

void addPatient() {
    Patient p;
    printf("Enter patient ID: ");
    scanf("%d", &p.id);
    printf("Enter patient name: ");
    scanf("%s", p.name);
    printf("Enter patient priority: ");
    scanf("%d", &p.priority);
    heap[heapSize++] = p;
    heapifyUp(heapSize - 1);
}

void treatPatient() {
    if (heapSize) {
        Patient p = heap[0];
        printf("Treated patient ID: %d, Name: %s, Priority: %d\n", p.id, p.name, p.priority);
        heap[0] = heap[--heapSize];
        heapifyDown(0);
    } else {
        printf("No patients in the waiting queue.\n");
    }
}

void displayWaitingQueue() {
    if (heapSize) {
        printf("Waiting Queue:\n");
        for (int i = 0; i < heapSize; i++) {
            printf("Patient ID: %d, Name: %s, Priority: %d\n", heap[i].id, heap[i].name, heap[i].priority);
        }
    } else {
        printf("No patients in the waiting queue.\n");
    }
}

void checkPatientCount() {
    printf("Number of patients in the waiting queue: %d\n", heapSize);
}

void updatePatientPriority() {
    int id, priority;
    printf("Enter patient ID: ");
    scanf("%d", &id);
    for (int i = 0; i < heapSize; i++) {
        if (heap[i].id == id) {
            printf("Enter new priority: ");
            scanf("%d", &priority);
            heap[i].priority = priority;
            heapifyUp(i);
            printf("Patient priority updated.\n");
            return;
        }
    }
    printf("Patient not found.\n");
}

void clearWaitingQueue() {
    heapSize = 0;
    printf("Waiting queue cleared.\n");
}

int main() {
    int choice;
    do {
        printf("\nPatient Queue Management System\n");
        printf("1. Add a patient\n");
        printf("2. Treat a patient\n");
        printf("3. Display waiting queue\n");
        printf("4. Check patient count\n");
        printf("5. Update patient priority\n");
        printf("6. Clear waiting queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                treatPatient();
                break;
            case 3:
                displayWaitingQueue();
                break;
            case 4:
                checkPatientCount();
                break;
            case 5:
                updatePatientPriority();
                break;
            case 6:
                clearWaitingQueue();
                break;
            case 0:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}

