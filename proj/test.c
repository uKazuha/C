#include <stdio.h>
#include <windows.h>

void test(void);


int main(void){

    SetConsoleOutputCP(CP_UTF8);

    test();

    return 0;
}


void test(void){

    char name[6] = "asd\n";

    puts("测试函数：");

    printf("%d\n",strlen(name));


}