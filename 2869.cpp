#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> &p1, pair<int, int> &p2){
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    
    return p1.second < p2.second;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; // T개의 테스트 데이터, Floor, Room, NumberHuman 정보저장한 배열
    cin >> T;
    int testcase[T][3];
    // testcase에 정보 저장
    for (size_t i = 0; i < T; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cin >> testcase[i][j];
        }
    }

    // testcase 별로 하나씩 꺼내서 연산
    for (size_t i = 0; i < T; i++)
    {
        int floor, room, guest;
        floor = testcase[i][0];
        room = testcase[i][1];
        guest = testcase[i][2];


        int flag = 0;
        bool endflag = false;

        // 백터에 층수, 호수를 넣고 호수 - 층수 순으로 정렬
        vector <pair<int, int>> v;
        for (size_t j = 1; j <= floor; j++)
        {
            for (size_t k = 1; k <= room; k++)
            {
                v.push_back(pair<int,int>(j, k));
                flag++;
            }
        }
        sort(v.begin(), v.end(), comp);

        int ap1, ap2;
        ap1 = v[guest-1].first; ap2 = v[guest-1].second;
        string s_ap1 = to_string(ap1), s_ap2 = to_string(ap2);
        cout << ap1 << (ap2<10 ? '0' + s_ap2 : s_ap2) << "\n";
    }
    

    
    return 0;
}