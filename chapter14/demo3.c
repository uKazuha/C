/* 

    本例用来介绍向函数传递结构体信息的相关的基本知识：
        4.结构体中字符数组和字符指针
        5.匿名结构的使用
        6.复合字面量的使用

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TITLESIZE   31  //书名的容量
#define AUTHORSIZE 31   //作者姓名的容量


#define NAMESIZE 31 //人名的长度

#define GAMENAMESIZE   31     
#define COMPANYNAMESIZE 31

#define ARRSIZE 5   //数组的容量


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

//定义两个个结构体，里面要存两个字符串。
//一个用字符数组，一个用字符指针
struct game1{
    char gamename[GAMENAMESIZE];
    char *company;
};

//两个用字符数组
struct game2{
    char gamename[GAMENAMESIZE];
    char company[COMPANYNAMESIZE];
};

//计算两本书的总价
void sum(float,float);

//打印一本书的信息
void print(struct book);

//修改一本书的价格
void modify(struct book*);


int main(void){

    //下面来看一下两种定义的区别
    //game1
    struct game1 g1;
    //game2
    struct game2 g2;
    printf("the size of g1:%d\n",sizeof(g1));
    printf("the size of g2:%d\n",sizeof(g2));
    /*
        从输出上可以看出来，第一个大小为40，第二个大小为62
        也就说，当用字符数组的时候，结构体变量被创建时，系统分配了足够的空间，而如果用字符指针，则未准备空间，只有存放指针本身的空间
        这样会带来一个结果：存放在字符数组的内容，我们知道它限定在这个结构体的内存空间里，而字符指针则指向一个未知的地址
        即不知道这个地址后面有没有足够的空间来存放内容，如果不够则很可能覆盖掉某些重要的数据，所以这种方式不推荐
        如果实在要这么用，则应在其保存内容前，通过malloc函数主动申请一块内存空间，不用的时候再free掉，如下
    */

    strcpy(g1.gamename,"sekiro");
    g1.company = (char*)malloc(COMPANYNAMESIZE*sizeof(char));
    g1.company = "from software";

    printf("g1`s gamename is: %s and the company is: %s\n",g1.gamename,g1.company);

    

    /*
        5.匿名结构：这种方式用于嵌套结构里的成员，访问匿名结构的成员时，把其当作外层结构的成员即可，如
            struct person {
                char name[size];
                struct {int age;float weight;};
            }
            访问age：person.age
    */

    /*
        6.复合字面量：用于传递信息比较多如
            (strcut person){"Li Si",{"BAI JIA XING","NO",20.12}}
            相当于 5,"this is a string" 这种的字面量
        
        复合字面量支持结构体和数组，下面是数组的形式
            (int){1,2,3,4,5}
    */
    print((struct book){"BAI JIA XING","NO",20.12});
    



    free(g1.company);
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