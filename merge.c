#include <stdio.h>


int sorted[1000001]; // ���� �迭 : ��������

void merge(int a[], int m, int middle, int n) {
    int i = m;
    int j = middle +1;
    int k = m;
    // akjdkljfkljklㄴ어람널머ㅏㅓㅏㅣㅓㅣ
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
    // ���� �����͵� ����
    if (i > middle)
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
    //���ĵ� �迭�� ����
    for (int t = m; t <= n; t++)
    {
        a[t] = sorted[t];
    }
    return;
}

void mergeSort(int a[], int m, int n) {
    //�̿��� ���� ũ�Ⱑ 1���� ���
    if (m<n)
    {
        int middle = (m +n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle +1, n);
        merge(a, m, middle, n);
    }
    return;
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