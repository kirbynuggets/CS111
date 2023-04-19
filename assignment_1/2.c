#include <stdio.h>

void duplicateElements(int arr[], int n)
{
    int i, j;
    printf("Duplicate elements in the array are: ");
    for (i = 0; i < n; i++)
        {
        for (j = i + 1; j < n; j++)
         {
            if (arr[i] == arr[j])
            {
                printf("%d ", arr[j]);
                break;
            }
        }
    }
}

int remDuplicates(int arr[], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
        {
        for (j = i + 1; j < n;)
        {
            if (arr[i] == arr[j])
             {
                for (k = j; k < n; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;
            } else {
                j++;
            }
        }
    }
    printf("\n");
    return n;
}

int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 10, 20, 60, 70, 80, 80 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    duplicateElements(arr, n);
    printf("\n");

    n = remDuplicates(arr, n);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
