#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, G=1; // 21¾ï±îÁö
    cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        if (n > G)
        {
            G += i*6;
        }else{
            cout << i;
            break;
        }
    }
    return 0;
}