#include <stdio.h>



void decTobin(int n);



int main(void){

    int number;
    printf("请输入一个十进制整数:");
    scanf("%d",&number);
    printf("%d转成二进制数为：",number);
    decTobin(number);

}



void decTobin(int n){

    if(n != 0){
        decTobin(n/2);
        printf("%d",n%2);
    }
}