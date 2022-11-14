#include <iostream>
using namespace std;



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c; // 고정비용, 건당 인건비, 총 판매수익
    cin >> a >> b >> c;
    if (b >= c)
    {
        cout << -1;
        return 0;
    }
    
    cout << a/(c-b) + 1; // 고정비용 / 순이익 => 고정 비용과 일치하거나 나머지가 남음 +1 하면 여기서부터 순이익이 남음
    
    return 0;
}