//Linear Search final revision
#include <stdio.h>
#include <stdlib.h>

void linearSearch(int n, int *A, int *searchElement){
    int flag=0;
    for(int i=0; i<n; i++){
        if(A[i]== *searchElement){
            flag=1;
            printf("Element found at index %d\n", i);
        }
    }
    if(flag==0){
        printf("Element not found.");
    }
}

int main(){
    int n, searchElement;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter %d elements in array: ", n);
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    printf("Enter the element you want to find: ");
    scanf("%d",&searchElement);
    linearSearch(n,A, &searchElement);
    return 0;
}
