#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);


/*
 * Complete the 'largestMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int bigest(int arr_rows, int arr_columns, int** arr, int i, int j, int size){
    int kickout = 1;
    int holdi = i;
    int holdj = j;
    int hold = 0;
    if (i + size > arr_rows || j + size > arr_columns)
        return -1;
    while (i < (holdi + size) && i < arr_rows && kickout){
        j = 0;
        while (j < (holdj + size) && j < arr_columns){
        // printf("==> j = %d i = %d size = %d <", j, i, i + size);
            if (arr[i][j] == 0)
                kickout = 0;
            j++;
        }
        // printf("now\n");
        i++;
    }
    if (kickout == 1){
        // printf("in %d =", kickout);
        hold = bigest(arr_rows, arr_columns, arr, holdi, holdj, 1 + size);
        // printf("back %d =", hold);
    }
    if (kickout == 0)
    return -1;
    if (hold > size)
        return hold;
    return size;
}

int largestMatrix(int arr_rows, int arr_columns, int** arr) {
    int i = 0;
    int j = 0;
    int high = 0;
    int hold = 0;

    while (i < arr_rows){
        j = 0;
        while (j < arr_columns && arr[i][j] == 1){
            // printf("d\n");
            hold = bigest(arr_rows, arr_columns, arr, i, j, 1);
            if (hold > high)
                high = hold;
            j++;
        }
        i++;
    }
    return high;
}

int main()
{
    int **i2 = (int**)malloc(sizeof(int*) * 3);
        i2[0] = (int*)malloc(sizeof(int) * 3);
        i2[1] = (int*)malloc(sizeof(int) * 3);
        i2[2] = (int*)malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            i2[i][j] = 0;
    i2[0][0] = 1;
    i2[1][0] = 1;
    i2[1][1] = 1;
    i2[0][1] = 1;
    // i2[1][2] = 1;
    // i2[2][1] = 1;
    // i2[1][0] = 1;
    // i2[0][1] = 1;
    printf("%d",largestMatrix( 3, 3, i2));
    return 0;
}