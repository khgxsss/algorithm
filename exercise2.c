#include <stdio.h>

void swap(int* arr, int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int median_of_three(int arr[], int left, int right){
    int median = (left+right)/2;
    int list[3] = {left, median, right};
    if (arr[list[0]] > arr[list[1]])
    {
        swap(list, 0, 1);
    }
    if (arr[list[1]] > arr[list[2]])
    {
        swap(list, 1, 2);
    }
    if (arr[list[0]] > arr[list[1]])
    {
        swap(list, 0, 1);
    }

    return list[1];
}

int quickSort_inside(int* arr, int start, int end){
    int i,j,pIdx,pivot;
    i = start +1;
    j = end;
    pIdx = median_of_three(arr, start, end);
    pivot = arr[pIdx];
    swap(arr, start, pIdx);

    while (i<=j)
    {
        while (arr[i] <= pivot && i <= end)
        {
            i++;
        }
        while (arr[j] >= pivot && j >=start + 1)
        {
            j--;
        }
        if (i <= j)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, j, start);

    return j;
}

void quickSort(int* arr, int start, int end){
    if (start >= end)
    {
        return;
    }
    int pivot = quickSort_inside(arr, start, end);
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
    
    return;
}

void insertionSort(int *arr, int num){
    int i,j,temp;
    for ( i = 1; i < num; i++)
    {
        j = i-1;
        temp = arr[i];
        while ( j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        
    }
    
}

int main(void){

    int list[6] = {777,3463,123418,214,24,75};

    // quickSort(list, 0, 5);
    insertionSort(list, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d \n", list[i]);
    }
    

    return 0;
}