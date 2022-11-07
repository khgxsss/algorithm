int sorted[100];

void merge(int array[], int m, int middle, int n){
    int i = m;
    int j = middle + 1;
    int k = m;

    while (i <=middle && j<=n)
    {
        if (array[i] <= array[j])
        {
            sorted[k] = array[i];
            i++;
        }else {
            sorted[k] = array[j];
            j++;
        }
        k++;
    }
    if (i > middle)
    {
        for (int t = j; t <= n; t++)
        {
            sorted[k] = array[t];
            k++;
        }
        
    }else {
        for (int t = i; t <= middle; t++)
        {
            sorted[k] = array[t];
            k++;
        }
    }
    for (int t = 0; t <= n; t++)
    {
        array[t] = sorted[t];
    }
    
}

void mergeSort(int array[], int m, int n){
    if (m < n){
        int middle = (m+n)/2;
        mergeSort(array, m, middle);
        mergeSort(array, middle+1, n);
        merge(array, m, middle, n);
    }
}

int main(void){
    int number;
    scanf("%d", &number);
    int array[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &array[i]);
    }
    
    
    mergeSort(array, 0, number-1);
    for (int i = 0; i < number; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}