#include <stdio.h>

void heapify(int A[], int n, int i, int isMaxheap)
{
    int temp, min, leftc, rightc;
    min = i;
    leftc = 2 * i + 1;
    rightc = 2 * i + 2;
    if (isMaxheap)
    {
        if (leftc < n && A[leftc] > A[min])
        min = leftc;
        if (rightc < n && A[rightc] > A[min])
        min = rightc;
    }
    else
    {
        if (leftc < n && A[leftc] < A[min])
        min = leftc;
        if (rightc < n && A[rightc] < A[min])
        min = rightc;
    }

    if (min != i)
    {
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
        heapify(A, n, min, isMaxheap);
    }
}


void heapsort(int A[], int n, int isMaxheap)
{
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(A, n, i, isMaxheap);
    }
    printf("\nHeap array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    for (i = n - 1; i > 0; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapify(A, i, 0, isMaxheap);
    }
}


void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    printf("%d ", A[i]);
    printf("\n");
}


int main()
{
    int A[20], n, i, ch = 9;
    printf("\nEnter size of array: ");
    scanf("%d", &n);
    printf("\nEnter elements in array: ");
    for (i = 0; i < n; i++)
    scanf("%d", &A[i]);
    while (ch != 3)
    {
        printf("\nMenu:");
        printf("\n1. Min heap ");
        printf("\n2. Max heap ");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                heapsort(A, n, 1);
                printf("\nSorted in Ascending Order (Min Heap):");
                display(A, n);
                break;
            case 2:
                heapsort(A, n, 0);
                printf("\nSorted in Descending Order (Max Heap): ");
                display(A, n);
                break;
            case 3:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
