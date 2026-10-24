/*
    本例用来介绍：
        1.联合体
        2.枚举类型

        什么是联合体？简单来说，联合体是一种可以存放多种数据类型的形式，它和结构体不一样，
        结构体中列出的成员可以被同时保存，而联合体中的成员只有一种可以被保存

        什么是枚举类型？枚举类型其实是一个整型，可以用枚举类型的地方都可以用整型来代替
*/

#include <stdio.h>
#include <string.h>

/*
    通过union关键字来定义一个联合体，形式与结构体一样
*/
union u
{
    char name[32];
    char *ch;
    int age;
};

/*
    通过enum关键字定义一个枚举类型，类型名为color
    这些标识符代表了一系列数，按位升序，默认从0开始
    可以指定赋值，但是在被指定赋值的元素之后，将会在此值之上依此递增
    注意：枚举类型不能自增自减，这说明了red,orange这些是字面量

    枚举类型是为了提高程序的可读性和可维护性，只能在程序里使用
*/
enum color {red,orange,yellow,green};




int main(void){

    //声明一个联合体变量
    union u info;
    printf("%zd\n",sizeof(info));
    /*
        以上输出了 32 ,这说明联合体被创建时，只会给它分配其最大成员所需的容量，这也解释了为什么
        联合体变量只能同时存储一个成员信息
    */
   //关于联合成员的访问
   strcpy(info.name,"store name");
   printf("%s\n",info.name);

   //覆盖信息,发现覆盖失败。即一个联合体变量只能存储一个值，这样看来联合体的作用比较小
//    info.age = 22;
//    printf("%s\n",info.age);


    printf("%d\n",red);
    
    enum color purple;
    // purple = 1;最好不要这样做，不然枚举类型就没有意义了
    purple = green;

    printf("%d\n",purple);

    return 0;
}