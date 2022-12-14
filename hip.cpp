#include <iostream>

using namespace std;

void swap(int* arr, int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void heapsort(int* heap, int size){
    // 힙 만들기
    for (int i = 0; i < size; i++)
    {
        int c = i;
        
        do
        {
            int root = (c-1)/2;
            if (heap[root] < heap[c])
            {
                swap(heap, root, c);
            }
            c = root;
        } while (c != 0);
    }
    // 크기를 줄여가며 반복적으로 힙을 구성
    for (int i = size-1; i >= 0; i--)
    {
        // 가장 큰 값을 맨 뒤로 보내고
        swap(heap, 0 , i);
        int c = 1;
        int root = 0;
        
        
        do
        {
            c = root*2 +1;
            // 자식 중에 더 큰 값을 찾기 (이진트리의 왼, 오)
            if (heap[c] < heap[c+1] && c < i-1)
            {
                c++; // 더 큰 값
            }
            // 루트보다 자식이 더 크다면 교환
            if (heap[root] < heap[c] && c < i)
            {
                swap(heap, root, c);
            }
            root = c; // 재귀적으로 힙 구조 만들어주기

        } while (c <i);
        
    }
    
    
          
}


int main(int argc, char const *argv[])
{
    int heap[10] = {10,1,9,2,8,3,7,4,6,5};
    heapsort(heap, sizeof(heap)/sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        cout << heap[i] << endl;
    }
    
    return 0;
}


