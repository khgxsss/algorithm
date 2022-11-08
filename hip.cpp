#include <iostream>
#include <algorithm>

using namespace std;

void heapsort(int* heap){

    // 힙 만들기
    for (int i = 0; i < 9; i++)
    {
        int c =i;
        do {
            int root = (c-1)/2;
            if (heap[root] < heap[c])
            {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    // 크기를 줄여가며 반복적으로 힙을 구성
    for (int i = 9-1; i >= 0; i--)
    {   
        for (int i = 0; i < 9; i++)
        {
            cout << heap[i] << endl;
        }
        cout << "==" << endl;
        // 가장 큰 값을 맨 뒤로 보내고
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = 1;
        do
        {
            c = 2 * root + 1;
            // 자식 중에 더 큰 값을 찾기 (이진트리의 왼, 오)
            if (heap[c] < heap[c+1] && c < i-1)
            {
                c++; // 더 큰 값
            }
            // 루트보다 자식이 더 크다면 교환
            if (heap[root] < heap[c] && c < i)
            {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c; // 재귀적으로 힙 구조 만들어주기
            
        } while (c < i);
        
    }
}

int main(int argc, const char** argv) {

    int heap[9] = {10,8,9,7,6,4,5,3,1};
    heapsort(heap);
    for (int i = 0; i < 9; i++)
    {
        cout << heap[i] << endl;
    }
    
    return 0;
}