#include <stdio.h>

void Heapsort(int [], int);
void Heapify(int [], int, int);

void Heapsort(int A[], int n)
{
    int i, temp;

    for(i = n/2; i >= 1; i--)
    {
        Heapify(A, n, i);
    }

    // Heap Sort
    for(i = n; i > 1; i--)
    {
        temp = A[1];
        A[1] = A[i];
        A[i] = temp;

        Heapify(A, i-1, 1);
    }
}

void Heapify(int A[], int n, int i)
{
    int largest = i;
    int L = 2*i;
    int R = 2*i + 1;
    int temp;

    if(L <= n && A[L] > A[largest])
    {
        largest = L;
    }

    if(R <= n && A[R] > A[largest])
    {
        largest = R;
    }

    if(i != largest)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        Heapify(A, n, largest);
    }
}

int main()
{
    int n;

    printf("Enter size of Array: ");
    scanf("%d", &n);

    int A[n+1];

    printf("Enter Elements of Array:\n");

    for(int i = 1; i <= n; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &A[i]);
    }

    Heapsort(A, n);

    printf("\nSorted Array:\n");

    for(int i = 1; i <= n; i++)
    {
        printf("%d\t", A[i]);
    }

    return 0;
}