#include <stdio.h>

int Partition(int [], int, int);
void Quick(int [], int , int );

int Partition(int A[], int lb, int ub) {
    int pivot = A[lb];
    int Start = lb;
    int End = ub;
    int temp;

    while (Start < End) {

        while (Start < ub && A[Start] <= pivot) {
            Start++;
        }
    
        while (A[End] > pivot) {
            End--;
        }
        if (Start < End) {
            temp = A[Start];
            A[Start] = A[End];
            A[End] = temp;
        }
    }
   
    temp = A[lb];
    A[lb] = A[End];
    A[End] = temp;

    return End;
}

void Quick(int A[], int lb, int ub) {
    int loc;
    if (lb < ub) {
        loc = Partition(A, lb, ub);
        Quick(A, lb, loc - 1);
        Quick(A, loc + 1, ub);
    }
}

void main() {
    int n;
    printf("Enter size of Array: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter Elements of Array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    int lb = 0;
    int ub = n - 1;
    Quick(A, lb, ub);

  
    printf("\nSorted Array:\n");
    for (int i = 0; i <n; i++) {
        printf("%d\t", A[i]);
    }
}
