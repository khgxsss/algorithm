#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    int b = 1; // �밢���� ��ġ
    int i = 1; // �� ��

    //X ��° �м��� �ִ� �밢���� ��ġ�� ���� ������
    //�� �밢���� ������ �м��� ��ȣ�� X�� ���� �̿��� X ��° �м��� ���� ����ߴ�.

    cin >> a;
    
    while (a > b)
    {
        i++;
        b += i;
    }

    if ( i % 2 == 0) //¦����
    {
        cout << i - (b - a) << "/" << 1 + (b -a);
    }else {
        cout << 1 + (b-a) << "/" << i - (b -a);
    }
    
    
    return 0;
}