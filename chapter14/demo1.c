/* 

    本例用来介绍结构体相关的基本知识：
    1.结构体是什么，有什么用
    2.如何定义一个结构体，struct关键字
    3.结构体的成员怎么访问
    4.怎么初始化一个结构体
    5.结构体数组
    6.嵌套结构体
    7.结构体指针

*/

#include <stdio.h>
#include <string.h>


#define TITLESIZE   31  //书名的容量
#define AUTHORSIZE 31   //作者姓名的容量
#define ARRSIZE 5   //数组的容量

#define NAMESIZE 31 //人名的长度

//定义一个结构体
/*
    如下：一本书，有书名、作者以及售价，像这样的信息被集合在一起，构成了一个结构体
        结构体的每个成员类型可能各不相同，用于记录不同的信息，这就是结构体的作用
*/
//使用struct关键字定义一个结构体，其中book是自定义的一个类型名称，与int、char这种类似，当然可以省略book
//但是你必须做好只使用一次的准备，即定义时即声明并初始化一个变量，或者使用typedef，这个后面再说  
struct book{
    char title[TITLESIZE];
    char author[AUTHORSIZE];
    float price;
};

//下面是一个嵌套结构体
//这个结构体记录了一个人的信息，有名字，还有最喜欢的书的相关信息
struct person{
    char name[NAMESIZE];
    struct book favoritebook;
};


int main(void){

    //声明并初始化一个结构体
    // 简单声明
    // struct book book1;
    //这是一种最常用的初始化方式
    struct book book1 = {
        "nothing is impossible",
        "Zou Xianjin",
        20.12
    };

    //还有一种是通过初始化器，与数组的类似
    /*
        请注意：如果部分使用初始化器，则该位置后一个元素将被用来初始化下一个单位。
            另外，如果多次对一个成员初始化，该成员的值是最后一次被赋的值
    */
    struct book book2 = {
        .title = "SAN ZI JING",
        .author = "nobody",
        .price = 30.31
    };

    //接下来访问成员，通过 . 操作符来访问
    printf("%s\n",book1.author);

    //接下来展示如何创建一个结构体数组，很简单，像普通数据类型创建数组时一样。结构体数组中每一元素都是一个结构体
    // struct book bookarr[ARRSIZE];
    // 初始化
    struct book bookarr[ARRSIZE] = {
        {"nothing is impossible","zou",23.1},
        {"QIAN ZI WEN","NOBODY",32.1},
        {"BOOK3","NOBODY",33.1},
        {"BOOK4","NOBODY",12.1},
        {"BOOK5","NOBODY",36.1}
    };
    //访问结构体数组的元素,例如访问第三本书的书名
    printf("%s\n",bookarr[2].title);

    //结构体里面当然也可以嵌套其他结构体，在开头定义一下
    //访问其中的结构体和访问其他成员一样
    //下面这种方式也提供一种先声明后赋值的初始化方式
    struct person zhangsan; //先声明了，先预备一个内存空间
    //下面这一行有个坑，即zhangsan.name是一个数组名，一个不可修改的值，一个char类型的数组，不能在声明后再进行这样操作
    // *(zhangsan.name) = "zhang san";
    strcpy(zhangsan.name,"zhang san");
    //下面这条语句说明了，一个结构体变量可以赋值给另一个同型的结构体
    zhangsan.favoritebook = book1;

    printf("zhangsan`s favorite book is <%s>\n",zhangsan.favoritebook.title);

    //接下来讲一下结构体指针
    puts("-----introduce the pointer of struction-----");
    /*
        与其他类型的指针类似，结构体指针存放的也是一个地址，它指向一个结构体的首地址
        注意：结构体的名称（变量名）并不是该结构体首地址的别名，这一点和数组不一样
    */
    //声明一个结构体指针
    // struct book *pbook;
    //声明一个结构体指针并初始化指向一个结构体
    struct book *pbook = &book1;

    //通过指针来访问结构体的成员：使用 -> 操作符
    puts("use the pointer to access struction`s member:");
    puts(pbook->title);

    return 0;
}