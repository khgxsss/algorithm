#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string, pair<int,int>> a, pair<string, pair<int,int>> b){
    if (a.second == b.second){
        return a.second.second > b.second.second;
    }else {
        return a.second.first > b.second.first;
    }
}

int main(int argc, const char** argv) {
    vector<pair<string, pair<int, int>>> v;
    v.push_back(pair<string, pair<int, int>>("박한울", pair<int, int>(90, 19961222)));
    v.push_back(pair<string, pair<int, int>>("최한울", pair<int, int>(920, 219961222)));
    v.push_back(pair<string, pair<int, int>>("김한울", pair<int, int>(930, 319961222)));
    v.push_back(pair<string, pair<int, int>>("이한울", pair<int, int>(930, 119961222)));
    v.push_back(pair<string, pair<int, int>>("남궁한울", pair<int, int>(950, 519961222)));

    sort(v.begin(), v.end(), compare);
    for (int  i = 0; i < v.size(); i++)
    {
        /* code */
        cout << v[i].first << ' ' << v[i].second.first << endl;
    }
    

    return 0;
}