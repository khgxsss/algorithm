#include <iostream>

using namespace std;

struct Student
{
    private:
    int id;
    char *name;
    float percentage;

    public:
    void Show() {
        cout << "미미미ㅣ: " << id << endl;
        cout << "�̸�: " << name << endl;
        cout << "�����: " << percentage << endl;
    }
    void setInfo(int _id, char *_name, float _percentage);
};

void Student::setInfo(int _id, char *_name, float _percentage) {
    id = _id;
    name = _name;
    percentage = _percentage;
}


int main() {
    Student stu;
    stu.setInfo(1, "��ö��", 90.5);
    stu.Show();
    return 0;
}