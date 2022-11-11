#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> coordinate;
    vector<int> coordinate_copy;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        coordinate.push_back(x);
    }
    coordinate_copy = coordinate;

    sort(coordinate_copy.begin(), coordinate_copy.end());
    coordinate_copy.erase(unique(coordinate_copy.begin(), coordinate_copy.end()), coordinate_copy.end());

    for (int i = 0; i < N; i++)
    {
        // 정렬된 상태에서 find 보다 lower_bound 가 더 빠르다..
        auto value = lower_bound(coordinate_copy.begin(), coordinate_copy.end(), coordinate.at(i));
        int index = value - coordinate_copy.begin();
        cout << index << " ";
    }
    
    return 0;
}
