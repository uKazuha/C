/* 

    本例用来介绍向函数传递结构体信息的相关的基本知识：
        7.伸缩型数组
            伸缩型数组用来记录一些数据，数量可能不确定，根据需要"扩容"
        它要求：
            1.结构里必须至少有一个成员
            2.伸缩型数组必须放在最后面
            3.数组的[]的不能有内容 

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
    假定现在有这么个结构体：用来记录分数、分数的个数、平均分
*/
struct flex
{
    int count;
    double average;
    double score[];
};





int main(void){

    /*
        事实上，当声明一个有伸缩型数组的结构体时，系统并不会为这个数组分配空间，
        且其本意不是希望你声明一个结构体变量，而是希望你创建一个指向这个结构体的指针，
        并通过malloc函数来为其分配你需要的空间大小，如下
    */

    struct flex *ptr;
    ptr = malloc(sizeof(struct flex) + 5*sizeof(double));   //这里的malloc前面不进行强制类型转换也是可以的，但C++必须转
    //通过以上定义：我们获取了一个指针，指向了一块能容纳struct flex 和 5个double型数据地址
    //后面如果希望多加进去几个数据，则可以重新分配内存

    free(ptr);
    return 0;
}