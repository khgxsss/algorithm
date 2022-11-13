#include <iostream>
using namespace std;

long long int arr[1000001][2];

long long int calc(int x){
    
    // 점화식 dp[n] = 2*dp[n-1] + 3*dp[n-2] + 2*dp[n-3] + 2*dp[n-4] + ... + 2*dp[1] + 2*dp[0] 입니다.
    arr[0][0] = 1;
    arr[1][0] = 2;
    arr[2][0] = 7;
    arr[2][1] = 0;
    // 3보다 같거나 클 때 경우의 수 2가지 추가
    for (int i = 3; i <= x; i++)
    { // n-4까지의 합(Sum(n-4))+ arr[x-3][0] 부터 arr[0][0] 까지 합산된 값(Sum(n-3)) i-3은 특수패턴이 시작되는 곳부터 계산함을 의미
        arr[i][1] = (arr[i-1][1] + arr[i-3][0])%1000000007; //오버플로우 방지
        // arr[i][1] = 1;
        arr[i][0] = (2*arr[i-1][0] + 3*arr[i-2][0] + 2* arr[i][1])%1000000007;
    }
    return arr[x][0];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num;

    cout << calc(num);
    
    return 0;
}
