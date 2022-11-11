#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    int** arr1 = new int* [N];
    for (int i = 0; i < N; i++)
    {
        arr1[i] = new int[M];
    }
    int** arr2 = new int* [N];
    for (int i = 0; i < N; i++)
    {
        arr2[i] = new int[M];
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr1[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr2[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr1[i][j] += arr2[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << "\n";
    }
    
    
    for (int i = 0; i < N; i++)
    {
        delete[] arr1[i];
    }
    delete[] arr1;

    for (int i = 0; i < N; i++)
    {
        delete[] arr2[i];
    }
    delete[] arr2;
    
    return 0;
}
