//binary search final revision
#include <stdio.h>
#include <stdlib.h>

void binarySearch(int A[], int low, int high, int searchElement){
    int flag=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(A[mid]==searchElement){
            flag=1;
            printf("Element found at index %d", mid);
            break;
        }
        else if(A[mid]>searchElement){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if (flag==0){
        printf("Element not found.");
    }
}

int main(){
    int n, searchElement;
    printf("Enter no. of elements in array: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter elements of array(%d): ", n);
    for(int i=0; i<n; i++){
       scanf("%d", &A[i]);
    }
    printf("Enter element you want to search:");
    scanf("%d", &searchElement);
    int low=0;
    int high=n-1;
    binarySearch(A, low, high, searchElement);
    return 0;
}
