#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}


int main(void) {
    int a[10] = {9,3,5,1,43,24,2,1,3,5};
    
    sort(a, a+10, compare);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << ' ';
    }
    
}