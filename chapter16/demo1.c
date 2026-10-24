/*
    本例介绍：
        1.在预处理器之前做了哪些工作
        2.#define预处理指令

    1.翻译阶段：
        ①会将源代码中的字符映射到源字符集
            即原始代码中不管以何种编码格式：UTF8、GBK等,保存下来的字节流，统统转换成编译器使用的编码格式（源字符集对应的字节流），
            这一举措消除了编码格式的差异，更利于国际化
        ②将物理行转换为逻辑行：检查源码中每一处出现的反斜杠，并消除其后跟着的换行符
            例如，printf("this is not a\
            complete line\n");   →   printf("this is not acomplete line\n");
            这里的消除的换行符，指的是输入代码时，按下的[enter]键所产生的换行，不是双引号里显式输入的\n
        ③文本划分：将源代码中的文本内容划分为3类
            -预处理记号序列：所谓的记号就是用空格、制表符、换行符隔开的内容，如 x * 2,x和2是两个记号
            -空白序列
            -注释序列：注释序列会被替换成一个空格
    
    2.#define预处理指令：#define 宏名 替换列表
        注意：宏只做替换，不做计算
    
*/

#include <stdio.h>

//字符常量
#define TWO 2
//常量表达式
#define FOUR TWO*TWO
//宏函数与使用参数
#define MAX(X,Y) X>Y?X:Y
//宏的可变参数：宏名里使用...,替换列表里使用__VA_ARGS__
#define PR(...) printf(__VA_ARGS__)
//#用在替换列表里，将参数转换成字符串
#define PRT(x) printf("the var:"#x" is:%d\n",x)
//##用在替换列表里，记号粘合剂。这里MNAME(1)被x1替换
#define MNAME(n) x##n

int main(void){

    printf("TWO is:%d\n",TWO);
    printf("FOUR is:%d\n",FOUR);
    printf("MAX(X,Y) is:%d\n",MAX(TWO,FOUR));

    PR("FOUR is:%d,TWO is:%d\n",FOUR,TWO);

    int v1 = 100;
    int v2 = 200;
    PRT(v1);
    PRT(v2);

    int MNAME(1) = 1;
    int MNAME(2) = 2;

    PRT(x1);
    PRT(x2);

    return 0;
}