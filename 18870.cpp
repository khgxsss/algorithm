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
        // ���ĵ� ���¿��� find ���� lower_bound �� �� ������.
        auto value = lower_bound(coordinate_copy.begin(), coordinate_copy.end(), coordinate.at(i));
        int index = value - coordinate_copy.begin();
        cout << index << " ";
    }
    
    return 0;
}
