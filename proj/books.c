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
bool delete(PBook head);




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

        case 3:
            delete(head);
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
    printf("3：删除图书(根据书名)\n");
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
        scanf("%s",node->bookname);     //此处用scanf来接收存在bug，即用户可能输入空白字符，后面再优化
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


//根据图书名字删除
//当用户输入3指令进入到这个函数时，输入流里还有 '\n' 这个字符，需要注意
//要么在程序开始时，先清空输入流getchar()
//要么在正式读取时处理
bool delete(PBook head){

    while(getchar() != '\n')    continue;

    char name[SIZEOFBOOKNAME];
    PBook temp=head;  // 将temp指向头节点
    PBook last=head;  // 由于是用单链表记录信息，所以当定位到目标结点时，需要记录上一个结点的地址。也可思考其他的方式

    puts("请输入您要删除的图书名：");
    /*
        从标准输入中获取书名，读到允许的最长字符串或遇到结尾时停止，并在结尾加一个'\0'
        最大能读SIZEOFBOOKNAME个字符，但是实际会读SIZEOFBOOKNAME-1个，因为要加'\0'

        fgets()有以下情况：
            1.输入换行符时，前面的字符数小于最大允许容量 → XXXXX\n\0
    */
    fgets(name,SIZEOFBOOKNAME,stdin);   

    //由于fgets会将换行符'\n'也当作一个字符记录
    //stelen()不会将'\0'也算上，所以得出的数就是最后一个位置的使用下标,即'\0'
    if( name[strlen(name)-1] == '\n')   name[strlen(name)-1] = '\0';

    //根据图书名，定位到目标结点
    while( temp != NULL && strcmp(temp->bookname,name) != 0){
        last=temp;
        temp = temp->next;
    }    
        
    if(temp == NULL){
        fprintf(stderr,"未查到书籍 %s 的相应信息！\n",name);
        return false;
    }

    //修改链接
    last->next = temp->next;
    free(temp);
    puts("删除成功！");
    return true;
}

