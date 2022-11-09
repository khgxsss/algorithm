#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

class Student
{
private:
    
    /* data */
public:

    string name;
    int score;
    Student(string name, int score){
        this->name = name;
        this->score = score;
    };

    bool operator < (Student& student) {
        return this->score <student.score;
    }

    // ~Student(){
    //     cout << "?†Œë©?" << endl ;
    // };
};



int main(void) {
    int a[10] = {9,3,5,1,43,24,2,1,3,5};
    Student students[] = {
        Student("a", 90),
        Student("b", 88),
        Student("c", 63),
        Student("d", 42),
        Student("e", 70)
    };
    
    // sort(a, a+10, compare);
    sort(students, students +5);

    for (int i = 0; i < 5; i++)
    {
        cout << students[i].name << ' ' << students[i].score << endl;
    }
    
}