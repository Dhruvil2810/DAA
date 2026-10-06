#include<stdio.h>

int smallestEvenMultiple(int n) {
    if(n %2 ==0){
        printf("Samllest The smallest multiple of both %d and 2 is %d. ", n, n);
    }else{
        int result = n*2;
        printf("Samllest The smallest multiple of both %d and 2 is %d. ", n, result);
    }
}

void main(){
    smallestEvenMultiple(11);
}