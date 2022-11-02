#include <stdio.h>

void swap(int* arr, int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int median_of_three(int* arr, int left, int right){
    int samples[3] = {left, (left+right)/2, right};
    if (arr[samples[0]]>arr[samples[1]])
    {
        swap(samples, 0, 1);
    }
    if (arr[samples[1]]>arr[samples[2]])
    {
        swap(samples, 1, 2);
    }
    if (arr[samples[0]]>arr[samples[1]])
    {
        swap(samples, 0, 1);
    }
    return samples[1];
}

int quickSort(int* arr,int start,int end){
    int temp, i, j, pIdx, pivot;
    i = start + 1;
    j = end;
    pIdx = median_of_three(arr, start, end);
    pivot = arr[pIdx];

    swap(arr, start, pIdx);

    while (j >= i)
    {
        while (arr[i] <= pivot && i <= end)
        {
            i ++;
        }
        while (arr[j] >= pivot && j >= start+1)
        {
            j--;
        }
        if (j >= i)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, j, start);

    return j;
}

void quickSort_out(int* arr, int start, int end){
    if (start > end){
        return ;
    }
    int pivot = quickSort(arr, start, end);
    quickSort_out(arr, start, pivot-1);
    quickSort_out(arr, pivot+1, end);
    
}

void insertionSort(int* arr, int num){
    int i, j, temp;
    for ( i = 1; i < num; i++)
    {
        temp = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    
    return;
}

int main(void){

    int inputNum;
    
    
    scanf("%d", &inputNum);

    int initList[inputNum];

    for (int t = 0; t < inputNum; t++)
    {
        scanf("%d", &initList[t]);
    }
    

    if (inputNum < 100)
    {
        insertionSort(initList, inputNum);
    }else {
        
        quickSort_out(initList, 0, inputNum-1);
    }

    for (int i = 0; i < sizeof(initList)/sizeof(int); i++)
    {
        printf("%d\n",initList[i]);
    }
    
    return 0;
}