#include<stdio.h>

void insertion(int [] , int );
void insertion(int A[],int n){
    int key, j;

    for(int i = 1 ; i<n ; i++){
        key = A[i];
        j = i-1;
        
        while(j>=0 && A[j]> key){
            A[j+1] = A[j];
            j = j-1;
        }

        A[j+1] = key;
    }

    printf("Sorted Array:");
    for(int i = 0 ; i<n ; i++){
        printf("%d\t", A[i]);
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

    insertion(A, n);
}