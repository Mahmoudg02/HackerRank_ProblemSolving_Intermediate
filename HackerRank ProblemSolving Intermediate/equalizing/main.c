#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
int  dp[200001][2] = { 0 };

int minOperations(int arr[], int threshold, int d, int arr_count)
{
    //sorting
    int temp = 0;
    for (int i = 0; i < arr_count; i++)
    {
        for (int j = i + 1; j < arr_count; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int minO = INT_MAX;

    for (int i = 0; i < arr_count; i++)
    {
        int steps = 0;
        while (1)
        {
            int x = arr[i];
            dp[x][0] += 1;
            dp[x][1] += steps;
            if (dp[x][0] >= threshold)
                minO = ( minO <= dp[x][1] )? minO : dp[x][1];
            if (x == 0)
                break;
            arr[i] /= d;
            steps += 1;
        }
    }
    return minO;
}

int main()
{
    int i = 0, n,w;

    FILE* file;
    int td[2] = { 0 };
    int t = 0;
    int d = 0;
//    if (file = fopen("t4.txt", "r"))
//    {
//        fscanf(file, "%d", &n);
//        int* arr = (int*)calloc(sizeof(int), n);
//        while (i < n)
//        {
//            fscanf(file, "%d", &arr[i]);
//            i++;
//
//        }
//        i = 0;
//        while (fscanf(file, "%d", &td[i]) != EOF)
//        {
//            i++;
//        }
//        fclose(file);
//
//        clock_t tStart = clock();
//        t = td[0];
//        d = td[1];
//
//
//        int x = minOperations(arr, t, d, n);
//        printf("minOperations = %d\n", x);
//        printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
//    }

    int arr[]={64,
                30,
                25,
                33};
    t=2 ;
    d=2;
    int x = minOperations(arr, t, d, sizeof (arr)/sizeof (int));
    printf("minOperations = %d\n", x);
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}