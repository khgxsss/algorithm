#include <stdio.h>

int sorted[10];

void merge(int arr[], int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;

    while (i <= middle && j <= n)
    {
        if (arr[i] <= arr[j])
        {
            i++;
        }else {
            j++;
        }
        k++;
    }
    if (i > middle)
    {
        for (int t = j; t <= n ; i++)
        {
            sorted[k] = arr[t];
            k++;
        }
        
    }else {
        for (int t = i; t <= middle; t++)
        {
            sorted[k] = arr[t];
            k++;
        }
        
    }
    for (int t = m; t <= n ; i++)
    {
        arr[t] = sorted[t];
    }
    return;
}

void mergeSort(int a[], int m, int n){
    if (m<n){
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle+1, n);
        merge(a, m, middle, n);
    }
    return;
}

int main(void){
    int array[7] = {6,5,21,2,6,8,44};
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;   
}