#include<stdio.h>
#include<string.h>

int main() {
    
    char source[32] = "���� ��� �޸� �Դϴ�. �̰���";
    char dest[10] = "�� �޸�";

    printf("���� �� : %s\n", dest);

    memmove(dest, source, sizeof(source));
    printf("���� �� : %s\n", dest);
}