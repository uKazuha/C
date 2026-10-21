#include <stdio.h>

int count_char();

int main(void){

    int count;
    count = count_char();
    printf("总字符数为(去掉空格字符以及换行符)：%d\n",count);
    return 0;
}

int count_char(){

    char ch;
    int count=0;
    while ((ch = getchar()) != EOF){

        if (ch == '\n' || ch == ' ') continue;

        count++;
    }
    
    return count;

}