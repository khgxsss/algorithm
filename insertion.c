#include <stdio.h>
void insertionSort(int*arr, int num){
    int i,j,temp;
    for ( i = 1; i < num; i++)
    {
        temp = arr[i];
        j=i-1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(void){
    int arr[4] = {888,55,3,1};

    insertionSort(arr, 4);

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    
    
    return 0;
}