#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, V;
    int reached = 0;
    cin >> A >> B >> V;
    int day = 1;
    while (reached < V)
    {
        if (reached + A >= V)
        {
            day++;
            break;
        }
        
        reached += A;
        reached -= B;
        cout << "reached" << reached << endl;
        cout << "day" << day << endl;
        
        day++;
    }
    
    cout << day;

    
    return 0;
}