#include <iostream>
using namespace std;



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c; // �������, �Ǵ� �ΰǺ�, �� �Ǹż���
    cin >> a >> b >> c;
    if (b >= c)
    {
        cout << -1;
        return 0;
    }
    
    cout << a/(c-b) + 1; // ������� / ������ => ���� ���� ��ġ�ϰų� �������� ���� +1 �ϸ� ���⼭���� �������� ����
    
    return 0;
}