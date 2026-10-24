/*
    定义一个函数，这个函数有两个参数，第一个为char类型的指针，第二个为整型
    功能：用以捕获用户的输入一定大小，当用键入换行符时代表此行结束，将用户输入的换行符替换成'\0'，
          若用户的输入长度超出所限制，则将该行的剩余字符清空。

*/

#include <stdio.h>
#include <string.h>

#define MAX 11

char *s_gets(char *,int);


int main(void){

    char content[MAX];
    char *ans;
    puts("enter the next you want");
    puts("end with an empty line:");
    //不停接受用户的内容并回显，直到输入空行：换行符开头的行
    ans = s_gets(content,MAX);
    while (ans != NULL && ans[0] != '\0')
    {
        puts("enter the next you want");
        puts("end with an empty line:");
        puts("what you input is:");
        puts(content);
        ans = s_gets(content,MAX);
    }
    
    puts("Bye!");

    return 0;
}



char *s_gets(char *str,int n){

    char *ch;   //用来保存换行符的地址，以便替换为'\0'
    char *ret;

    ret = fgets(str,n,stdin);   //获取失败则返回NULL

    //如果不为空，则查找换行符
    if (ret)
    {
        ch = strchr(ret,'\n');  //查找成功则返回该字符的地址值，否则为NULL
        if(ch)  //因为用户输入换行符代表输入结束，如果找到换行符了，说明输入流里没有东西了
            *ch = '\0';
        else
            while (getchar() != '\n')  continue;    //否则肯定还有内容，需清空
    }

    return ret;
}