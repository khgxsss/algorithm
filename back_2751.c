// quick + median of three + insertion

#include <stdio.h>

void Swap(int arr[],int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int sort_three(int* arr,int left,int right){
    int samples[3] = {left,(left+right)/2,right}; //values is index
    if(arr[samples[0]]>arr[samples[1]])
           Swap(samples,0,1);
    if(arr[samples[1]] > arr[samples[2]])
        Swap(samples, 1, 2);
    if(arr[samples[0]]>arr[samples[1]])
        Swap(samples, 0, 1);
        
    return samples[1];
}

int quickSort(int* arr, int start, int end){
    int temp, i, j, length;
    i = start + 1;
    j = end;
    int pIdx = sort_three(arr, start, end);
    int pivot = arr[pIdx];

    
    while ( j >= i)
    {
        while (arr[i] <= arr[start] && i<=end)
        {
            i++;
        }
        while (arr[j] >= arr[start] && j>start)
        {
            j--;
        }
        if (i > j)
        {
            temp = arr[start];
            arr[start] = arr[j];
            arr[j] = temp;
        }else {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
    }

    return j;
}

void quickSort_out(int* arr, int start, int end){

    if (start > end)
    {
        return;
    }
    int pivot = quickSort(arr, start, end);
    quickSort_out(arr, start, pivot-1);
    quickSort_out(arr, pivot+1, end);
    
}

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
    return;
}

int main(void)
{
    int inputNum;
    
    
    scanf("%d", &inputNum);

    int initList[inputNum];

    for (int t = 0; t < inputNum; t++)
    {
        scanf("%d", &initList[t]);
    }
    

    if (inputNum < 75)
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



