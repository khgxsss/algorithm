#include <iostream>

using namespace std;

class student {
    private:
        char * name;
        int age;
        char * hobby;
    public:
        void ShowInfo();
        void SetInfo(char *_name, int _age, char *_hobby);
        void Study();
        void Sleep();
};

void student::ShowInfo()
{
    cout << "�̸� : " << name << " ����: " << age << " ���:" <<hobby << endl;
}

void student::SetInfo(char *_name, int _age, char *_hobby)
{
    name = _name;
    age = _age;
    hobby = _hobby;
}

void student::Study()
{
    cout << "����!!" << endl;
}

void student::Sleep()
{
    cout << "��!" << endl;
}

int main()
{
    student stu;

    stu.SetInfo("��ö��", 16, "��ǻ�� ����");
    stu.ShowInfo();

    int i =1;
    while (true)
    {
        if (i > 9) break;
        stu.Study();
        stu.Sleep();
        i++;
    }

    return 0;
}