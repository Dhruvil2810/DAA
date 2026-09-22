// #include <stdio.h>
// #include <limits.h>
// void main()
// {
//     int d[100], no, i, j, k, S, q;
//     int m[100][100];

//     printf("Enter no of matrices: ");
//     scanf("%d", &no);

//     printf("Enter dimensions:\n");
//     for(i = 0; i <= no; i++)
//     {
//         printf("Value of d[%d]: ", i);
//         scanf("%d", &d[i]);
//     }

//     for(i = 1; i <= no; i++)
//     {
//         m[i][i] = 0;
//     }

//     for(S = 2; S <= no; S++)
//     {
//         for(i = 1; i <= no - S + 1; i++)
//         {
//             j = i + S - 1;
//             m[i][j] = INT_MAX;

//             for(k = i; k <i + S - 1; k++)
//             {
//                 q = m[i][k] + m[k+1][j] + d[i-1] * d[k] * d[j];

//                 if(q < m[i][j])
//                 {
//                     m[i][j] = q;
//                 }
//             }
//         }
//     }

//     printf("\nDP Table:\n");
//     for(i = 1; i <= no; i++)
//     {
//         for(j = 1; j <= no; j++)
//         {
//             if(j < i)
//                 printf("%8s", "-");
//             else
//                 printf("%8d", m[i][j]);
//         }
//         printf("\n");
//     }

//     printf("\nMinimum number of multiplications = %d\n", m[1][no]);
// }
