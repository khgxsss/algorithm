#include <iostream>
using namespace std;

long long int arr[1000001][2];

long long int calc(int x){
    
    // ��ȭ�� dp[n] = 2*dp[n-1] + 3*dp[n-2] + 2*dp[n-3] + 2*dp[n-4] + ... + 2*dp[1] + 2*dp[0] �Դϴ�.
    arr[0][0] = 1;
    arr[1][0] = 2;
    arr[2][0] = 7;
    arr[2][1] = 0;
    // 3���� ���ų� Ŭ �� ����� �� 2���� �߰�
    for (int i = 3; i <= x; i++)
    { // n-4������ ��(Sum(n-4))+ arr[x-3][0] ���� arr[0][0] ���� �ջ�� ��(Sum(n-3)) i-3�� Ư�������� ���۵Ǵ� ������ ������� �ǹ�
        arr[i][1] = (arr[i-1][1] + arr[i-3][0])%1000000007; //�����÷ο� ����
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
