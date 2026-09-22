#include <stdio.h>

void selection(int [] , int);
void selection(int A[],int n){
    int mV, mI, temp;
    for(int i =0 ; i<n ; i++){
        mV = A[i];
        mI = i;

        for( int j = i+1; j<n; j++){
            if( mV> A[j]){
                mV = A[j];
                mI = j;
            }
        }

        temp = A[mI];
        A[mI] = A[i];
        A[i] = temp;
    }

    printf("Sorted Array:");
    for(int i = 0 ; i<n ; i++){
        printf("%5d\t", A[i]);
    }
}

void main(){
    int n;
    printf("Enter size of Array:");
    scanf("%d", &n);

    int A[n];

    printf("Enter Elements of Array:\n");
    for(int i = 0 ; i<n ; i++){
        printf("Element %d:", i+1);
        scanf("%d", &A[i]);
    }

    selection(A, n);
}