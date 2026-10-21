#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#define SIZEOFBOOKNAME 32
#define SIZEOFAUTHORNAME 32
#define SIZEOFID 10

typedef struct book{

    char bookname[SIZEOFBOOKNAME];
    char author[SIZEOFAUTHORNAME];
    char id[SIZEOFID];
    float price;
    struct book *next;

}Book,*PBook;

// typedef struct {
//     Book node;
// }head,*phead;


void menu(void);
void allbooks(PBook head);
PBook init(void);   //初始化图书管理系统，并返回一个头指针(头结点) 
bool add(PBook head);




int main(void){
    SetConsoleOutputCP(CP_UTF8);

    PBook head = NULL;
    head = init();
    menu();

    int order;
    printf("请输入指令(任意字符将退出)：\n");
    
    while (scanf("%d",&order) == 1)
    {
        switch (order)
        {
        case 1:
            allbooks(head);
            break;
        
        case 2:
            add(head);
            break;
        
        default:
            break;
        }

        printf("请输入指令(任意字符将退出)：\n");

    }
    





    return 0;
}


void menu(void){
    int i;
    for ( i = 0; i < 40; i++)
    {
        putchar('#');
    }
    putchar('\n');

    printf("1：查看所有图书\n");
    printf("2：新增图书\n");
    printf("3：删除图书\n");
    printf("4：修改图书信息\n");
    printf("5：退出\n");

    for ( i = 0; i < 40; i++)
    {
        putchar('#');
    }
    putchar('\n');
}

void allbooks(PBook head){

    if (head->next == NULL)
    {
        printf("无任何图书！！！\n");
        return;
    }
    

    PBook temp = head->next;

    while (temp != NULL)
    {
        putchar('\n');
        printf("书名：%s\n",temp->bookname);
        printf("作者：%s\n",temp->author);
        printf("编号：%s\n",temp->id);
        printf("价格：%.2f\n",temp->price);
        putchar('\n');
        temp = temp->next;
    }
    

}

PBook init(void){
    PBook head = (PBook)malloc(sizeof(Book));

    if (head != NULL)
    {
        head->next = NULL;
        return head;
    }
    
    printf("初始化失败！！！\n");
    return NULL;
}

bool add(PBook head){

    PBook node = (PBook)malloc(sizeof(Book));
    node->next = NULL;

    if (node != NULL)
    {
        printf("请输入书名：\n");
        scanf("%s",node->bookname);
        printf("请输入作者：\n");
        scanf("%s",node->author);
        printf("请输入编号：\n");
        scanf("%s",node->id);
        printf("请输入价格：\n");
        scanf("%f",&(node->price));

        node->next = head->next;
        head->next = node;

        printf("添加成功！\n");
        return true;
    }
    

    return false;
}
