    #include <stdio.h>

    void main()
    {
        int i, j, no, cap;
        int w[100], v[100], p[100][100];

        printf("Enter No of elements: ");
        scanf("%d", &no);

        printf("Enter Weight and Value:\n");

        for(i = 1; i <= no; i++)
        {
            printf("\nElement %d:\n", i);

            printf("Weight of %d: ", i);
            scanf("%d", &w[i]);

            printf("Value of %d: ", i);
            scanf("%d", &v[i]);
        }

        printf("\nEnter Capacity: ");
        scanf("%d", &cap);

        for(i = 0; i <= no; i++)
        {
            for(j = 0; j <= cap; j++)
            {
                p[i][j] = 0;
            }
        }

        for(i = 1; i <= no; i++)
        {
            for(j = 1; j <= cap; j++)
            {
                if(j < w[i])
                {
                    p[i][j] = p[i-1][j];
                }
                else
                {                
                    if(p[i-1][j] > v[i] + p[i-1][j-w[i]])
                    {
                        p[i][j] = p[i-1][j];
                    }
                    else
                    {
                        p[i][j] = v[i] + p[i-1][j-w[i]];
                    }
                }
            }
        }

        printf("\nTable:\n");

        for(i = 0; i <= no; i++)
        {
            for(j = 0; j <= cap; j++)
            {
                printf("%5d", p[i][j]);
            }
            printf("\n");
        }

        printf("\nMaximum Profit = %d\n", p[no][cap]);

    }