/*
    任务：从一个文件末尾，倒序输出文件的内容

    fseek()、ftell()


*/


#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp;
    char *filename = "demo.txt";
    long count;
    char ch;

    fp = fopen(filename,"rb");  //以二进制只读的方式打开

    if(fp == NULL){
        fprintf(stderr,"文件打开失败！\n");
        exit(EXIT_FAILURE);
    }

    fseek(fp,0L,SEEK_END);  //将文件指针移到最后一个字节
    count = ftell(fp);      //ftell(fp)返回一个long类型，意思是当前文件指针距离文件开头有多少个字节

    for(int i = 1; i <= count; i++){
        fseek(fp,-i,SEEK_END);  //回退
        ch = getc(fp);
        if(ch != EOF)  putchar(ch);
    }


    fclose(fp);
    return 0;
}