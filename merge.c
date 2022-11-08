#include <stdio.h>

int sorted[8];

void merge(int a[], int m, int middle, int n) {
    int i = m;
    int j = middle +1;
    int k = m;

    while (i <=middle && j <= n)
    {
        if (a[i] <=a[j])
        {
            sorted[k] = a[i];
            i++;
        }else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    if ( i > middle)
    {
        for (int t = j; t <= n; t++)
        {
            sorted[k] = a[t];
            k++;
        }
        
    }else {
        for (int t = i; t <= middle; t++)
        {
            sorted[k] = a[t];
            k++;
        }
    }
    for (int t = m; t <= n; t++)
    {
        a[t] = sorted[t];  
    }
    
}

void mergeSort(int a[], int m, int n){
    if (m < n) {
        
    }
}