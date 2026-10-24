/*
    任务：将一个整数，转化成一个字符串，并保存在变量中

    关键点：
        1.获取每一位的数字：例如43，43/10=4。。。3，所以个位为3，然后用商4进入下一轮：4/10=0。。。4，所以十位为4，因为商为0，停止
        2.将该数字 + '0' 的结果赋值给一个char变量
*/

#include <stdio.h>
#include <stdlib.h>

char *intTostr(int num);


int main(){

    int num = 34;

    printf("%d\n",-10/3);

    return 0;
}

char *intTostr(int num){

    int remainder;  //记录余数
    char ch;    //记录字符
    char *res = (char*)malloc(32*sizeof(char));
    int i=0;

    //将数拆分成一个个的字符形式
    //'0'到'9'的ascii码值为 48~57
    //如果商为零则停止
    while(num/10 != 0 && i<31){
        ch = num%10 + '0';
        res[i] = ch;
        num /= 10;
        i++;
    }


    remainder = num%10;
    if (remainder != 0)
    {
        res[++i] = remainder + '0';
    }

    res[++i] = '\0';
    puts(res);

    return res;
}