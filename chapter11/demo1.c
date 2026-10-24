#include <stdio.h>
#include <stdlib.h>

void modify(int * restrict);


int main(void){

    char *commands[5] = {
        "git status",
        "git commit -m",
        "git add .",
        "a git line",
        "there is no keyword"
    };

    int * restrict ptr = (int*)malloc(10*sizeof(int));

    int * ptr2 = ptr;

    
    return 0;
}