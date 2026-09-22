#include<stdio.h>

void Heapsort(int [], int);
void Heapify(int [], int , int );

void Heapsort(int A[], int n) 
{
    int i, temp;
    
    for(i = (n-1)/2; i>=0; i--)
    {
        Heapify(A,n,i);
    }

    for(i= n-1; i>0; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        Heapify(A,i,0);
    }
    
}

void Heapify(int A[], int n, int i) 
{
    int largest = i;
    int L = (2*i)+1;
    int R = (2*i)+2;
    int temp;

    if(L<n && A[L] > A[largest])
    {
        largest = L;
    }

    if(R<n && A[R] > A[largest])
    {
        largest = R;
    }

    if(i != largest)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        Heapify(A,n,largest);
    } 

}

void main() {
    int n;
    printf("Enter size of Array: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter Elements of Array:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    Heapsort(A,n);


    printf("\nSorted Array:\n");

    for (int i = 0; i <n; i++)
    {
        printf("%d\t", A[i]);
    }
}
