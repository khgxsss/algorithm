#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, string> p1, pair<int, string> p2){
    return p1.first < p2.first;
}

int main(int argc, char const *argv[])
{
    int pp_num;
    cin >> pp_num;
    vector<pair<int, string>> pp_list;

    for (size_t i = 0; i < pp_num; i++)
    {
        int x; string y;
        cin >> x >> y;
        pp_list.push_back(pair<int, string>(x, y));
    }
    stable_sort(pp_list.begin(), pp_list.end(), comp);

    for (size_t i = 0; i < pp_num; i++)
    {
        cout << pp_list.at(i).first << " " << pp_list.at(i).second << "\n";
    }
    
    return 0;
}
