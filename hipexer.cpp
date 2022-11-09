#include <iostream>

using namespace std;

void swap(int* arr, int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void heapsort(int* heap, int size){

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
    
    for (int i = size-1; i >= 0; i--)
    {
        swap(heap, 0 , i);
        int c = 1;
        int root = 0;
        
        
        do
        {
            c = root*2 +1;
            if (heap[c] < heap[c+1] && c < i-1)
            {
                c++;
            }
            if (heap[root] < heap[c] && c < i)
            {
                swap(heap, root, c);
            }
            root = c;

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


