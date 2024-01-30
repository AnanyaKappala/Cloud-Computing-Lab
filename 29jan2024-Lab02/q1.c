/* WAP in C for min-min scheduling algorithm.
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
    int minMin[50][50];
    int tmp[50][50];
    int makespan = 0;
    printf("Fill Data: \n");
    for (int i = 0; i < nM; i++)
        for (int j = 0; j < nT; j++)
        {
            scanf("%d", &minMin[i][j]);
            tmp[i][j] = minMin[i][j];
        }
    printf("Original Data: \n");
    for (int i = 0; i < nM; i++)
    {
        for (int j = 0; j < nT; j++)
            printf("%d ", minMin[i][j]);
        printf("\n");
    }
    int resultTask[50] = {0};
    int resultMachine[50] = {0};
    int resultTime[50] = {0};
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
                if (minMin[i][j] < minimum)
                {
                    minimum = minMin[i][j];
                    pos = i;
                }
            }
            time[j] = minimum;
            machine[j] = pos;
        }
        int minimum = INT_MAX;
        int pos = -1;

        for (int j = 0; j < nT; j++)
        {
            if (time[j] < minimum)
            {
                minimum = time[j];
                pos = j;
            }
        }
        resultTask[++ptr] = pos;
        resultMachine[ptr] = machine[pos];
        resultTime[ptr] = tmp[machine[pos]][pos];
        if (minimum > makespan)
            makespan = minimum;
        for (int i = 0; i < nM; i++)
        {
            for (int j = 0; j < nT; j++)
            {
                if (j == resultTask[ptr])
                    minMin[i][j] = INT_MAX;
                else if (i == resultMachine[ptr] && minMin[i][j] != INT_MAX)
                    minMin[i][j] += minimum;
                else
                    continue;
            }
        }
    }
    printf("Scheduled Task are :\n");
    for (int i = 0; i < nT; i++)
    {
        printf("Task %d Runs on Machine %d with Time %d units\n", resultTask[i] + 1, resultMachine[i] + 1, resultTime[i]);
    }
    printf("Makespan : %d units\n", makespan);
    return 0;
}