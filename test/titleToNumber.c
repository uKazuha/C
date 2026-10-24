/* 
    任务:将一个给定的excel表列字符串，转换成整数
    A:1
    B:2
    .
    .
    .
    Z:26
    AA:27

    例如 title:"A",则返回1，tiele:"AB",则返回28

    思考：
        什么是模操作？一个数模另一个数的结果是什么？有什么规律？
        例如：num % 10,结果是0~9的任意一个数，一共10种结果
        而问题中：每一位可能出现的结果多达26种，则需要模26，每一位的结果是0~25
        可是对应关系是1~26，所以这里我们需要处理一下对应关系
        即在进行取模运算前，将数值减1。最后将模的结果 + 'A'即可得到该位的正确符号

    用数学公式（建模）来进行解答
    一个有n位的EXCEL格式的数是：[a(n-1)][a(n-2)]···[a(0)],对于任意的0≤ i <n,[a(i)]的范围是 1~26
    转换成十进制数是：[a(n-1)][a(n-2)]···[a(0)] == sum{ [a(n-1)] * 26expr{n-1} + [a(n-2)] * 26expr{n-2} + ... + [a(0)] }
    现在我们知道了右边每一位[a(0)]的值，要求左边的数记为val：
    val = sum{ [a(n-1)] * 26expr{n-1} + [a(n-2)] * 26expr{n-2} + ... + [a(0)] }

*/
#include <stdio.h>
#include <stdlib.h>


char *convertToTitle(int val);

int main(void){

    char *str;
    int num = 23424;
    str = convertToTitle(num);
    printf("%s\n",str);

    return 0;
}


char *convertToTitle(int val){

    //创建一个字符指针保存每一轮循环得到的字符
    char *target = (char*)malloc(32*sizeof(char));
    int pos=0;

    while (val > 0)
    {
        val--;
        target[pos++] = val % 26 + 'A';
        val /= 26;
    }

    //反转数组
    char ch;
    for(int left = 0,right = pos-1; left < right; left++,right--){
        ch = target[left];
        target[left] = target[right];
        target[right] = ch;
    }
    
    //结尾加'\0'
    target[pos] = '\0';
    
    return target;
}