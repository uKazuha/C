#include <stdio.h>

// 字符输入/输出和输入验证
// 8.1 单字符IO：getchar()和putchar()


int main(void){

    // 使用while循环，当读到'#'停止

    char ch;

    while((ch=getchar()) != EOF){

        putchar(ch);

    }


    return 0;
}