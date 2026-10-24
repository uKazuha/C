/* 

    本例用来介绍向函数传递结构体信息的相关的基本知识：
    1.向函数传递结构体成员
    2.函数传递结构体（这在早期是不行的）
    3.向函数传递结构体指针

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

//计算两本书的总价
void sum(float,float);

//打印一本书的信息
void print(struct book);

//修改一本书的价格
void modify(struct book*);


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

    /*
        1.向函数传递结构体成员，假设需要买两本书，需要计算两本书的总价
    */
    sum(book1.price,book2.price);

   /*
        2.向函数传递结构体，打印这个结构体的信息
   */
    print(book2);

    /*
        3.向函数传递结构体指针，修改这个结构体的信息
    */
    modify(&book1);


    return 0;
}



//计算两本书的总价
void sum(float price1,float price2){

    puts("-----calculate the price of two books-----");
    double total = price1 + price2;
    printf("the total price is:%.2f\n",total);

}

//打印一本书的信息
void print(struct book b){
    puts("-----print the infomation of a book-----");
    printf("title:%s\tauthor:%s\tprice:%.2f\n",b.title,b.author,b.price);
}

//修改一本书的价格
void modify(struct book* b){
    float newprice;
    float oldprice;
    puts("-----modify the price of a book-----");
    puts("please input the new price:");

    scanf("%f",&newprice);
    oldprice = b->price;
    b->price = newprice;

    printf("the price have be modified,old price:%.2f,new price:%.2f\n",oldprice,newprice);
}