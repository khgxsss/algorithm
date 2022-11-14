#include <iostream>
using namespace std;

int dp[5001];//global 변수이기때문에 0으로 초기화된 배열


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, g;
    cin >> n;
    dp[3] = 1;
    dp[5] = 1;
    for (size_t i = 6; i <= n; i++)
    {
        if (dp[i-3])
        {
            dp[i] = dp[i-3] + 1;
        }
        if (dp[i-5])
        {
            dp[i] = dp[i] ? min(dp[i-5]+1, dp[i]) : dp[i-5] + 1;
        }
    }
    g = dp[n] ? dp[n] : -1;
    cout << g;
    
    
    return 0;
}