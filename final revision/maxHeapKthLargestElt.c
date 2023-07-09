#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to heapify a subtree rooted at index i in the max-heap
void maxHeapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    maxHeapify(arr, n, largest);
  }
}

// Function to build a max-heap from an array
void buildMaxHeap(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    maxHeapify(arr, n, i);
  }
}

// Function to find the kth largest element in the max-heap
int kthLargest(int arr[], int n, int k) {
  for (int i = 0; i < k - 1; i++) {
    arr[0] = arr[n - 1];
    n--;
    maxHeapify(arr, n, 0);
  }
  return arr[0];
}

// Main function
int main() {
  int n, k;

  printf("Enter the number of elements in the max-heap: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements of the max-heap:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  buildMaxHeap(arr, n);

  printf("Enter the value of k: ");
  scanf("%d", &k);

  int kthLargestElement = kthLargest(arr, n, k);

  printf("The %dth largest element in the max-heap is: %d\n", k, kthLargestElement);

  return 0;
}
