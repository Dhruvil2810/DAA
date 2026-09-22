#include<stdio.h>

int Mergesort(int[], int , int);
int Merge(int[],int,int,int );


int Mergesort(int A[],int lb, int ub){
    int mid;
    if(lb<ub){
        mid = (lb+ub)/2;
        Mergesort(A, lb, mid);
        Mergesort(A, mid+1, ub);
        Merge(A,lb,mid,ub);
    }
}

int Merge(int A[],int lb, int mid, int ub)
{

    int i,j,k;
    int B[100];
    i = lb;
    k = lb;
    j = mid+1;

    while( i<=mid && j<= ub)
    {
        if(A[i]< A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    if(j>ub)
    {
        while(i<=mid)
        {
            B[k]=A[i];
            i++;
            k++;
        }
    }
    else if(i>mid)
    {
        while(j<=ub)
        {
            B[k] = A[j];
            j++;
            k++;
        }

    }



    for(int p = 0 ; p<=ub ; p++)
    {
        A[p] = B[p];
    }
}


void main(){
    int n,lb,ub,i;
    printf("Enter size of Array:");
    scanf("%d", &n);

    int A[n];

    printf("Enter Elements of Array:\n");
    for(int i = 0 ; i<n ; i++){
        printf("Element %d:", i+1);
        scanf("%d", &A[i]);
    }



    lb = 0;
    ub = n-1;

    Mergesort(A, lb,ub);
    for(i = 0 ; i<=ub ; i++)
    {

        printf("%5d",A[i]);
    }
}