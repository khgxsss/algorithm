#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[500001];
int countt[8001];
int N, a, b, c, d;
int sum = 0;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		countt[arr[i]+4000]++;
	}
	
	sort(arr, arr + N);
	
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

	for (int i = flag + 1; i < 8001; i++)
	{
		if (countt[i] == max)
		{
			flag = i;
			break;
		}
	}

	a = round(double(sum) / N);
	b = arr[(N - 1) / 2];
	c = flag - 4000;
	d = arr[N - 1] - arr[0];

	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << d << "\n";
}