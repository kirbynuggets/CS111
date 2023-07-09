#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

// Function to sort an array using insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to sort an array using bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to sort an array using quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to merge two sorted arrays
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to sort an array using merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    printf("Choose a sorting algorithm:\n");
    printf("1. Selection sort\n");
    printf("2. Insertion sort\n");
    printf("3. Bubble sort\n");
    printf("4. Quick sort\n");
    printf("5. Merge sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    clock_t start, end;
    double cpu_time_used;

    switch (choice) {
        case 1:
            start = clock();
            selectionSort(arr, n);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Sorted array using selection sort: ");
            printArray(arr, n);
            printf("Time taken: %f seconds\n", cpu_time_used);
            break;
        case 2:
            start = clock();
            insertionSort(arr, n);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Sorted array using insertion sort: ");
            printArray(arr, n);
            printf("Time taken: %f seconds\n", cpu_time_used);
            break;
        case 3:
            start = clock();
            bubbleSort(arr, n);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Sorted array using bubble sort: ");
            printArray(arr, n);
            printf("Time taken: %f seconds\n", cpu_time_used);
            break;
        case 4:
            start = clock();
            quickSort(arr, 0, n - 1);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Sorted array using quick sort: ");
            printArray(arr, n);
            printf("Time taken: %f seconds\n", cpu_time_used);
            break;
        case 5:
            start = clock();
            mergeSort(arr, 0, n - 1);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Sorted array using merge sort: ");
            printArray(arr, n);
            printf("Time taken: %f seconds\n", cpu_time_used);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
