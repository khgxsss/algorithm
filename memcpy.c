#include<stdio.h>
#include<string.h>

int main() {
    
    char source[32] = "복사 대상 메모리 입니다. 이것은";
    char dest[10] = "될 메모리";

    printf("복사 전 : %s\n", dest);

    memmove(dest, source, sizeof(source));
    printf("복사 후 : %s\n", dest);
}