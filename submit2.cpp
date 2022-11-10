#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[500001];
    int countt[8001];
    int N;
    int sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        countt[arr[i]+4000]++;
    }
    sort(arr, arr+N);
    int flag;
    int max = 0;

    for (int i = 0; i < 8001; i++)
    {
        if (countt[i] > max)
        {
            max = countt[i];
            flag = i;
        }
    }
    for (int i = flag + 1; i < 8001; i++) // 최빈값 중 두번째로 작은 값 출력
	{
		if (countt[i] == max)
		{
			flag = i;
			break;
		}
	}
    int a = round((double)sum/N);
    cout << a << "\n";
    cout << arr[(N-1)/2] << "\n";
    cout << flag-4000 << "\n";
    cout << arr[N-1] - arr[0];
    return 0;
}
