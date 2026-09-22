#include<stdio.h>

void main()
{
    int i = 1, n, temp, j, element =1;
    int A[100], S[100], F[100], sol[100];

    printf("Enter No of Activity: ");
    scanf("%d", &n);

    printf("Enter Start time and End time of avtivity:\n");

    for (i = 1; i <= n; i++)
    {
        printf("\nElement %d:\n", i);

        A[i] = i;
        printf("Start Time of %d: ", i);
        scanf("%d", &S[i]);

        printf("End Time of %d: ", i);
        scanf("%d", &F[i]);

    }

    // printf("\n\nUnsorted Activity  :");
    // for (i = 1; i <= n; i++)
    // {
    //     printf("%8d", A[i]);
    // }

    // printf("\nUnsorted Start time:");
    // for (i = 1; i <= n; i++)
    // {
    //     printf("%8d", S[i]);
    // }

    // printf("\nUnsorted End Time  :");
    // for (i = 1; i <= n; i++)
    // {
    //     printf("%8d", F[i]);
    // }

    for (i = 1; i <= n - 1; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (F[i] > F[j])
            {
                temp = F[i];
                F[i] = F[j];
                F[j] = temp;

                temp = S[i];
                S[i] = S[j];
                S[j] = temp;

                temp = A[i];
                A[i] = A[j];
                A[j] = temp;  
            }
        }
    }

    printf("\n\nActivity  :");
    for (i = 1; i <= n; i++)
    {
        printf("%8d", A[i]);
    }

    printf("\nStart time:");
    for (i = 1; i <= n; i++)
    {
        printf("%8d", S[i]);
    }

    printf("\nEnd Time  :");
    for (i = 1; i <= n; i++)
    {
        printf("%8d", F[i]);
    }

    sol[1] = A[1];
    i = 1;

    for(j = 2; j<=n; j++)
    {
        if(S[j] >= F[i])
        {
            element++;
            sol[element] = A[j];
            i = j;
        }
    }

    printf("\n\nsol : ");

    for(i = 1 ; i<=element; i++)
    {
        printf("%d\t", sol[i]);
    }
}