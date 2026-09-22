#include <stdio.h>

void main()
{
    int no, i, j, amount;
    int d[100], c[100][100];

    printf("Enter no of different coins: ");
    scanf("%d", &no);

    for(i = 0; i < no; i++)
    {
        printf("Enter coin %d value: ", i + 1);
        scanf("%d", &d[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    for(i = 0; i <= no; i++)
    {
        for(j = 0; j <= amount; j++)
        {
            c[i][j] = 0;
        }
    }

    for(i = 1; i <= no; i++)
    {
        for(j = 1; j <= amount; j++)
        {
            if(i == 1 && j < d[i-1])
            {
                c[i][j] = 999;
            }
            else if(i == 1)
            {
                c[i][j] = 1 + c[i][j - d[i-1]];
            }
            else if(j < d[i-1])
            {
                c[i][j] = c[i-1][j];
            }
            else
            {
                if(c[i-1][j] < 1 + c[i][j-d[i-1]])
                {
                    c[i][j] = c[i-1][j];
                }
                else
                {
                    c[i][j] = 1 + c[i][j-d[i-1]];
                }
            }
        }
    }

    printf("\nTable:\n");

    for(i = 0; i <= no; i++)
    {
        for(j = 0; j <= amount; j++)
        {
            if(c[i][j] == 999)
                printf("%5s", "INF");
            else
                printf("%5d", c[i][j]);
        }
        printf("\n");
    }
    printf("\nMinimum number of coins = %d\n", c[no][amount]);

    printf("\nCoins in solution set: ");

    i = no;
    j = amount;

    while(j > 0 && i > 0)
    {
        if(i > 1 && c[i][j] == c[i-1][j])
        {
            i--;
        }
        else
        {
            printf("%d ", d[i-1]);
            j = j - d[i-1];
        }
    }

    printf("\n");
}