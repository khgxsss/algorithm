#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    int b = 1; // 대각선의 위치
    int i = 1; // 줄 수

    //X 번째 분수가 있는 대각선의 위치를 구한 다음에
    //그 대각선의 마지막 분수의 번호와 X의 차를 이용해 X 번째 분수의 값을 출력했다.

    cin >> a;
    
    while (a > b)
    {
        i++;
        b += i;
    }

    if ( i % 2 == 0) //짝수면
    {
        cout << i - (b - a) << "/" << 1 + (b -a);
    }else {
        cout << 1 + (b-a) << "/" << i - (b -a);
    }
    
    
    return 0;
}