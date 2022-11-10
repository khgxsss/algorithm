#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool reverse_com(int a,int b){
    return a>b;
}

int main(int argc, char const *argv[])
{
    int initnum;
    vector<int> arr;

    cin >> initnum;
    
    // 백터로 만들기
    do
    {
        arr.push_back(initnum%10);
        initnum /=10;
    } while (initnum != 0);
    
    sort(arr.begin(), arr.end(), reverse_com);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr.at(i);
    }
    
    
    return 0;
}
