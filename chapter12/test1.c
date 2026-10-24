/*
    fprintf()、fscanf()、rewind()函数的使用

    FILE类型

    fopen()、fclose()

    任务：编写一个程序，要求用户输入一些文本内容，并保存在文件当中，输入完成后，从文件中读取并输出到屏幕上

    1.需要一个文件指针
    2.需要一个char类型的指针content，保存用户输入的内容
    3.用户输入通过fscanf()将内容从stdin存到content里
    4.通过fprint()将content里的内容输出(保存)到文件中
    5.通过在新的一行开始处输入 # 结束
    6.通过fscanf()将文件中的内容保存在content中
    7.通过fprinf()content的内容输出到stdout中



*/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define MAX 256


int main(void){

    SetConsoleOutputCP(CP_UTF8);

    FILE *fp;   //定义一个指向文件类型的指针，接收fopen()函数返回值
    char *filename = "demo.txt";    //文件名
    char *content = (char*)malloc(MAX*sizeof(char));    //分配一个能容纳MAX个char类型的内存空间，并将首地址给content

    fp = fopen(filename,"a+");  //以追加的形式打开

    if(fp == NULL){
        fprintf(stdout,"文件%s不存在！！\n",filename);
        free(content);
        exit(EXIT_FAILURE);
    }

    puts("请输入您想保存的内容");
    puts("在下一行的开头输入#作为结束：");

    /*
        fscanf(stdin,"%255s",content)   意思是从stdin中，以最大255个字符的宽度读取字符，遇到空格回车等停止，类似scanf
        注意，使用fscanf读取stdin的内容时，如果遇到'\n'是不会读取的，也就是说保存的内容是不会有换行符的
        假如用户输入一行数据后，想另开一行，如果这一行数据小于允许的最大容量，会怎么办？大于呢？
    */


    while (fscanf(stdin,"%255s",content)!=0 && content[0] != '#')
    {
        fprintf(fp,"%s\n",content); //这里手动加一个换行符
    }
    

    
    puts("您输入的内容为：");

    rewind(fp); //返回文件开头处

    while (fscanf(fp,"%255s",content) == 1 && content[0] != '#')
    {
        fprintf(stdout,"%s\n",content);
    }
    
    if(fclose(fp) != 0){
        fprintf(stderr,"关闭文件时发生了错误\n");
    }
    

    free(content);
    return 0;
}