#include <iostream>

using namespace std;

int main(){
    int studentNum, totalScore=0;
    int *studentScore;
    int i;

    cout << "�л� ���� �Է��ϼ���: ";
    cin >> studentNum;
    studentScore = new int[studentNum];

    for (i = 0; i < studentNum; i++)
    {
        cout << i +1 << "�� �л��� ����: ";
        cin >> studentScore[i];
        totalScore += studentScore[i];
    }

    cout << "��� �л��� ���: " << totalScore / studentNum << endl;
    delete []studentScore;

    studentScore = new int();
    
    return 0;
}