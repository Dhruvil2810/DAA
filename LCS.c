#include<stdio.h>
#include<string.h>

void print(int i, int j);
char X[100],Y[100], B[100][100];
int C[100][100],i,j,m,n;

void print(int i, int j)
{
    if(i==0 && j==0)
    {
        return;
    }

    if(B[i][j]=='d')
    {
        print(i-1,j-1);
        printf("%c",X[i-1]);
    }
    else if(B[i][j] == 'l')
    {
        print(i,j-1);
    }
    else if(B[i][j]=='u')
    {
        print(i-1,j);
    }
}

void main()
{
    printf("Enter String X:");
    scanf("%s",X);

    printf("Enter String Y:");
    scanf("%s",Y);

    m = strlen(X);
    n = strlen(Y);

    for(i=0; i<=m;i++)
    {
        for(j=0; j<=n;j++){
            C[i][j]=0;
        }
    }

    for(i=1; i<=m;i++)
    {
        for(j=1; j<=n;j++){
            if(X[i-1] == Y[j-1])
            {
                C[i][j] = C[i-1][j-1]+1;
                B[i][j]='d';
            }
            else if(X[i-1] != Y[j-1])
            {
                if(C[i][j-1]>C[i-1][j])
                {
                    C[i][j]= C[i][j-1];
                    B[i][j]='l';
                }
                else
                {
                    C[i][j]= C[i-1][j];
                    B[i][j]='u';
                }
            }
        }
    }

    for(i=0; i<=m;i++)
    {
        for(j=0; j<=n;j++){
            printf("%4d",C[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    for(i=0; i<=m;i++)
    {
        for(j=0; j<=n;j++){
            printf("%4c",B[i][j]);
        }
        printf("\n");
    }
    printf("LCS is: ");
    print(m,n);
}