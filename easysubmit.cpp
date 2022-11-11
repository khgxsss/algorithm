#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1;j <=i ; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    

    return 0;
}
