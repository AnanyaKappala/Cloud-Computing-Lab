/* WAP in C for Max-min scheduling algorithm.
Declare a 2d-array of size nM x nT
Data should be in the following format :
      T1   T2    T3
M1 | 140 | 20  | 60 |
M2 | 100 | 100 | 70 |*/
#include <stdio.h>
#include <limits.h>
int main()
{
    int nT, nM;
    printf("Enter number of machines and tasks: ");
    scanf("%d %d", &nM, &nT);
    int maxMin[50][50];
    int tmp[50][50];
    int makespan = 0;
    printf("Fill Data: \n");
    for (int i = 0; i < nM; i++)
        for (int j = 0; j < nT; j++)
        {
            scanf("%d", &maxMin[i][j]);
            tmp[i][j] = maxMin[i][j];
        }
    printf("Original Data: \n");
    for (int i = 0; i < nM; i++)
    {
        for (int j = 0; j < nT; j++)
            printf("%d ", maxMin[i][j]);
        printf("\n");
    }
    int resultTask[50];
    int resultMachine[50];
    int resultTime[50];
    int ptr = -1;
    while (ptr < nT - 1)
    {
        int time[50], machine[50];
        for (int j = 0; j < nT; j++)
        {
            int minimum = INT_MAX;
            int pos = -1;
            for (int i = 0; i < nM; i++)
            {
                if (maxMin[i][j] < minimum)
                {
                    minimum = maxMin[i][j];
                    pos = i;
                }
            }
            time[j] = minimum;
            machine[j] = pos;
        }
        int maximum = INT_MIN;
        int pos = -1;
        for (int j = 0; j < nT; j++)
        {
            if (time[j] > maximum && time[j] != INT_MAX)
            {
                maximum = time[j];
                pos = j;
            }
        }
        resultTask[++ptr] = pos;
        resultMachine[ptr] = machine[pos];
        resultTime[ptr] = tmp[machine[pos]][pos];
        if (maximum > makespan)
            makespan = maximum;
        for (int i = 0; i < nM; i++)
        {
            for (int j = 0; j < nT; j++)
            {
                if (j == resultTask[ptr])
                    maxMin[i][j] = INT_MAX;
                else if (i == resultMachine[ptr] && maxMin[i][j] != INT_MAX)
                    maxMin[i][j] += maximum;
                else
                    continue;
            }
        }
    }
    printf("Scheduled Task are: \n");
    for (int i = 0; i < nT; i++)
    {
        printf("Task %d Runs on Machine %d with Time %d units\n", resultTask[i] + 1, resultMachine[i] + 1, resultTime[i]);
    }
    printf("Total elapsed time : %d units", makespan);
    return 0;
}