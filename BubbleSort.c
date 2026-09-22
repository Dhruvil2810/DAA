#include<stdio.h>

void bubble(int A[], int n);

void bubble(int A[], int n) {
    int temp;

    for (int i = 0; i < n - 1; i++) {
        
        for (int j = 0; j < n - i - 1; j++) { 
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

 
    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
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

    bubble(A, n);
}