#include <iostream>

using namespace std;

int main(){
    int studentNum, totalScore=0;
    int *studentScore;
    int i;

    cout << "학생 수를 입력하세요: ";
    cin >> studentNum;
    studentScore = new int[studentNum];

    for (i = 0; i < studentNum; i++)
    {
        cout << i +1 << "번 학생의 점수: ";
        cin >> studentScore[i];
        totalScore += studentScore[i];
    }

    cout << "모든 학생의 평균: " << totalScore / studentNum << endl;
    delete []studentScore;

    studentScore = new int();
    
    return 0;
}