// #include <iostream>
// #include <algorithm>
#include <stdlib.h>

// using namespace std;

int main(void) {
    int size;
    printf("배열의 사이즈 : ");
    scanf_s("%d", &size);

    int** arr = (int**)malloc(sizeof(int*) * size);

    for (int i = 0; i < size; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * size);
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = i+j;
        }
        
    }
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            printf("arr[%d][%d] : %d\n", i,j,arr[i][j]);
        }
        printf("\n");
    }
        
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    
    free(arr);
    return 0;
}