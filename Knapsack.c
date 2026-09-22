#include <stdio.h>

int main()
{
    int i, j, n;
    float cap;
    float w[100], v[100], ratio[100], x[100];
    float temp, profit;

    printf("Enter No of elements: ");
    scanf("%d", &n);

    printf("Enter Weight and Value:\n");

    for (i = 1; i <= n; i++)
    {
        printf("\nElement %d:\n", i);

        printf("Weight of %d: ", i);
        scanf("%f", &w[i]);

        printf("Value of %d: ", i);
        scanf("%f", &v[i]);

        x[i] = 0.0;
        ratio[i] = v[i] / w[i];
    }


    printf("\nEnter Capacity: ");
    scanf("%f", &cap);

    printf("\n\nUnsorted Weight:");
    for (i = 1; i <= n; i++)
    {
        printf("%8.2f", w[i]);
    }

    printf("\nUnsorted Value:");
    for (i = 1; i <= n; i++)
    {
        printf("%8.2f", v[i]);
    }

    printf("\nUnsorted Ratio:");
    for (i = 1; i <= n; i++)
    {
        printf("%8.2f", ratio[i]);
    }

    for (i = 1; i <= n - 1; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    printf("\n\nSorted Weight : ");
    for (i = 1; i <= n; i++)
    {
        printf("%8.2f", w[i]);
    }

    printf("\nSorted Value  : ");
    for (i = 1; i <= n; i++)
    {
        printf("%8.2f", v[i]);
    }

    printf("\nSorted Ratio  : ");
    for (i = 1; i <= n; i++)
    {
        printf("%8.2f", ratio[i]);
    }

    profit = 0.0;

    for (i = 1; i <= n; i++)
    {
        if (w[i] <= cap)
        {
            x[i] = 1.0;
            profit = profit + (x[i] * v[i]);
            cap = cap - w[i];
        }
        else
        {
            x[i] = cap / w[i];
            profit = profit + (x[i] * v[i]);
            break;
        }
    }


    printf("\n\nTotal Profit = %.2f\n", profit);

    return 0;
}