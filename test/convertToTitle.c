/* 
    任务将一个给定的整数，转换成excel表列的表示方法
    A:1
    B:2
    .
    .
    .
    Z:26
    AA:27

    例如 num = 1，返回"A";num = 28,返回"AB"

    思考：
        什么是模操作？一个数模另一个数的结果是什么？有什么规律？
        例如：num % 10,结果是0~9的任意一个数，一共10种结果
        而问题中：每一位可能出现的结果多达26种，则需要模26，每一位的结果是0~25
        可是对应关系是1~26，所以这里我们需要处理一下对应关系
        即在进行取模运算前，将数值减1。最后将模的结果 + 'A'即可得到该位的正确符号

    用数学公式（建模）来进行解答
    一个有n位的EXCEL格式的数是：[a(n-1)][a(n-2)]···[a(0)],对于任意的0≤ i <n,[a(i)]的范围是 1~26
    转换成十进制数是：[a(n-1)][a(n-2)]···[a(0)] == sum{ [a(n-1)] * 26expr{n-1} + [a(n-2)] * 26expr{n-2} + ... + [a(0)] }
    现在我们知道了左边的数，记为val,需要求右边每一位[a(i)]的值：
    val == [a(0)] + 26*sum{ [a(n-1)] * 26expr{n-2} + [a(n-2)] * 26expr{n-3} + ... + [a(1)] }

    现在想通过除26把最低位的给去掉，而[a(0)]在1~26之间，所以两边减1后得
    val - 1 == [a(0)] - 1 + 26*sum{ [a(n-1)] * 26expr{n-2} + [a(n-2)] * 26expr{n-3} + ... + [a(1)] }
    再除26,故
    new_val = (val - 1)/26 == sum{ [a(n-1)] * 26expr{n-2} + [a(n-2)] * 26expr{n-3} + ... + [a(1)] }
    而此时[a(0)] - 1 == (val - 1)%26
    依此循环直到new_val == 0;
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