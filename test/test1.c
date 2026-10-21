/*
一共最多1000行命令，每个命令行长度最长200个字符，假定输入是这样的一个数组arr[ROW][COW]

任务：给出一个关键字（字串），返回这个关键字后面的关键字（子串）

关键点：①定位到关键字②通过偏移量定位到下一个关键字③下一个关键字之前可能存在空白字符，这会导致获取的下一个关键字的地址是错的
所以需过滤④保存


①定位可以用strstr(主串地址，子串地址)返回字串在主串的下标
②偏移量为①返回的下标➕子串的长度
③从②新定位的下标，循环判断当前字符是不是空白字符，直到真正的开始，并在再次遇到空格或者字符串结尾时停止


*/


#include <stdio.h>
#include <string.h>

#define ROW 5
#define COL 30 //字符串的\0



int main(void){


    /*
        分析一下下面这段代码：二维数组
        通过数组表示法表示一个二位数组，最内层的每个元素对应一个char类型的变量
        commands是数组名，也是这个二维数组的首地址，它应该是属于一个指针的指针，可以试试对其二次解引用**commands,正常输出。
        commands[0]代表了第一行，也应是一个指针，它是指向第一个数组元素（数组）的指针
        commands[0][0]代表了第一行的第一个元素，不是地址哦

        commands == commands[0] == &(commands[0][0])

        下面这种初始化二维数组的方法，会在每一个字符串的结尾加上'\0'

    */

    char *commands[ROW] = {
        "git status",
        "git commit -m",
        "git add .",
        "a git line",
        "there is no keyword"
    };
    char keyword[] = "git";
    int len = strlen(keyword);

 
    /*
        strstr(主串地址，子串地址)是一个用来在主串中匹配子串的函数，返回子串在主串中的首地址（char *），失配则返回NULL
    */
   char *idx;
   char *new_idx;
   for(int i = 0; i<ROW; i++){

        idx = strstr(commands[i],keyword);
        if(idx != NULL){

            new_idx = idx + len;
            while (*new_idx == ' ') new_idx++;


            /*
                要注意二维数组的存储依然是一维的，第一行git status存完后，下一个地址存放的是'\0',再下一个地址存放的才是第个字符串
                的首字符。
                所以需要的关键词后面如果还有其他字符，应该是' '，就用 != ' '来处理
                也有可能后面没有内容了，是字符串的结尾'\0'
            */

            while(*new_idx != ' ' && *new_idx != '\0'){
                putchar(*new_idx);
                new_idx++;
            }
        }

        putchar('\n');
   }
    
    return 0;
}