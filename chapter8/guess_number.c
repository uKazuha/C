#include <stdio.h>


int main(void){

    int guess = 1;
    char ch;

    printf("please keep a number(1~100) in your mind and I will guess it\n");
    printf("enter 'y' when im right and 'n' means wrong\n");
    printf("is it number %d ?\n",guess);

    while((ch=getchar()) != 'y'){
        printf("is it number %d?\n",++guess);

        while ((ch=getchar()) != '\n') continue;

    }

    printf("i know i can do it!\n");

    return 0;
}