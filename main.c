#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
//创建结构体及其成员
typedef struct Node
{
    char id[20];//编号
    char name[50];//书名
    float price;//价格
    struct LNode *next;//指针域
}S;//结构体定义为S
   //各函数定义
void choose();
void menudisplay(); //菜单函数
S *create();//创建链表函数
void input(S *);//新建条目
void print(S *);//输出链表函数
void pop_sort(S *);//排序
void insert(S *);//插入节点函数
void del(S *);//删除节点函数
void search(S *);//价格查找
void textinput(S *);//文件写入
void mod(S *);//修改图书信息
     //主函数
int main()
{
    choose();
}
void choose()
{
    S *head;
    int n, a = 1;//n用来控制选择操作类型，a控制循环，以-1终止
    while (a>0)
    {
        menudisplay();//显示菜单
        printf("请选择你要执行的操作:");
        scanf("%d", &n);//选择操作
        switch (n)//各操作数字对应菜单数字，通过n确定操作类型
        {
            case 1://创建
                head = create();
                break;
            case 2://输出
                //printf("图书信息为(按价格排序后)\n");
                //pop_sort(head);
                printf("编号\t书名\t价格\n");
                print(head);
                break;
            case 3://插入
                insert(head);
                printf("插入后\n");
                printf("编号\t书名\t价格\n");
                print(head);
                break;
            case 4://删除
                del(head);
                printf("删除后\n");
                printf("编号\t书名\t价格\n");
                print(head);
                break;
            case 5://取值
                get(head);
                break;
            case 6://价格查找
                search(head);
                break;
            case 7:
                input(head);
                printf("编号\t书名\t价格\n");
                print(head);
                break;
            case 8:
                textinput(head);
                printf("编号\t书名\t价格\n");
                print(head);
                break;
            default:
                a = -1;//跳出循环条件
                break;
        }
    }
}

//菜单模块直接显示
void menudisplay()
{
    printf("\n\n");
    printf("  欢迎使用图书管理系统\n");
    printf("|----------操作--------|\n");
    printf("1.创建                 |\n");
    printf("2.输出                 |\n");
    printf("3.插入                 |\n");
    printf("4.删除                 |\n");
    printf("5.取值                 |\n");
    printf("6.价格搜索             |\n");
    printf("7.添加                 |\n");
    printf("8.文件添加             |\n");
    printf("0.退出程序             |\n");
    printf("|----------------------|\n");
    printf("选择(1-8):\n");
}
//创建链表模块
S *create()
{
    S *head, *p, *q;//定义指针
    int i;
    head = (S *)malloc(sizeof(S));//头节点开辟空间
    head->next = NULL;//置空头节点的指针域
    printf("创建成功\n");
    q = head;//q指针记录头节点的地址
    p = head->next;//p指针记录头节点的指针域的地址

    int num=1;
    //scanf("%d", &num);
    while (num != 0)//输入书籍编号输入为零停止循环
    {
        p = (S *)malloc(sizeof(S));//p指针开辟空间
           //输入各成员
        //p->num = num;
        printf("请输入书的编号，名字以及价格,用空格隔开\n");
        scanf("%s %s %f", &p->id, &p->name,&p->price);
        p->next = NULL;//置空p节点的指针域
        q->next = p;//p，q节点连接
        q = p;//q指针后移
        printf("输入0结束输入,输入1继续输入\n");
        scanf("%d", &num);
    }
    return head;//返回链表的起始地址
}

//添加条目
void input(S *head)
{

    S *p, *q;//定义指针
    //q = head;//q指针记录头节点的地址
    p = head->next;//p指针记录头节点的指针域的地址
    int i = 0;
    while(p->next != NULL)
    {
        p = p->next;
    }
    int num=1;
    //scanf("%d", &num);
    while (num != 0)//输入书籍编号输入为零停止循环
    {
        q = (S *)malloc(sizeof(S));//p指针开辟空间
           //输入各成员
        //p->num = num;
        printf("请输入书的编号，名字以及价格,用空格隔开\n");
        scanf("%s %s %f", &q->id, &q->name,&q->price);
        q->next = p->next;
        p->next = q;//置空p节点的指针域
        //q = p;//p，q节点连接

        num = 0;
        //q = p;//q指针后移
        //printf("输入0结束输入,输入1继续输入\n");
        //scanf("%d", &num);
    }
    return head;//返回链表的起始地址


}

//通过文件添加数据
void textinput(S *head)
{
    FILE *fp;
    S *p, *q;//定义指针
    //q = head;//q指针记录头节点的地址
    p = head->next;//p指针记录头节点的指针域的地址
	int i = 0;
	int j = 0;
	float PRICE;//接收文件读出来的数据
	char  NAME[20], ID[20];
	fp = fopen("text.txt","r");//打开文件
	if(fp == NULL)
    {
        printf("读取文件失败\n");
        exit(0);
    }
    else
    {
        printf("添加文件成功\n");
    }
    /*if(p == NULL)
    {
        printf("请创建链表");
    }*/
    while(p->next != NULL)
    {
        p = p->next;
    }
    while(!feof(fp))
    {
        //fgets(line)
        q = (S *)malloc(sizeof(S));//p指针开辟空间
        //fscanf(fp,"%s %s %f", &ID, &NAME, &PRICE);
        fscanf(fp,"%s %s %f", &q->id, &q->name,&q->price);

        //q->id = ID;
        //q->name = NAME;
        //q->price = PRICE;

        q->next = p->next;
        p->next = q;//置空p节点的指针域
        p = q;

        //printf("读到的数据是:%s %s %.1f",ID,NAME,PRICE);
    }

}

//插入节点模块
void insert(S *head)
{
    int i=0, num, flag = 1;//flag实现判断指针是否到达最后一个节点
    S *p, *q, *r; //定义指针便于插入操作
    r = (S *)malloc(sizeof(S));//为r开辟空间
    q = head;//q指针记录头节点的地址

     //printf("please input a book's messages:\n");
    printf("选择要插入的位置和书本信息,包括编号，书名，价格，均用空格隔开\n");
    scanf("%d %s %s %f", &num, &r->id, &r->name, &r->price);
    while(i < num-1 ){
        q = q->next;
        i++;
    }
    if(q == NULL)
    {
        printf("插入位置超过表长");
    }else
    {
        r->next = q->next;
        q->next = r;
    }

    /*if(!q || i > num - 1){
        printf("插入失败");
    }else{
        r->next = q->next;
        q->next = r;
    }*/

}

//取值
void get(S *head)
{
    S *p, *q;//定义指针
    int i = 0;
    int b;//用于输入编号查找删除
    p = head;//p记录头节点的地址
    q = head->next;//q记录头节点的指针域的地址
    printf("输入你要获取的图书位置:");
    //输入编号
    scanf("%d", &b);
    while (q != NULL)//q不为空时执行循环
    {
        if (i == (b-1))//判断是否找到输入的编号
        {
            //为真时
            printf("书籍信息\n");
            printf("编号\t书名\t价格\n");
            printf("%s\t%s\t%.2f\n", p->id, p->name, p->price);
            break;
        }
        else
        {
            i++;
               //判断为假时
            p = p->next;//p指针后移
            q = q->next;//q指针后移
        }
    }
    if (p == NULL)//当查找到最后一个节点还未查到要删除的编号时，输出ERROR INPUT
    printf("ERROR INPUT\n");
}

//删除节点模块
void del(S *head)
{
    S *p, *q;//定义指针
    int i = 0;
    int b;//用于输入编号查找删除
    p = head;//p记录头节点的地址
    q = head->next;//q记录头节点的指针域的地址
    printf("输入你要删除的图书位置:");
    //输入编号
    scanf("%d", &b);
    while (q != NULL)//q不为空时执行循环
    {
        if (i == (b-1))//判断是否找到输入的编号
      //为真时
        {
            p->next = q->next;//断开q节点
            free(q);//释放q节点neicun
            q = NULL; //置空q指针防止出现野指针
        }
        else
        {
            i++;
            //判断为假时
            p = p->next;//p指针后移
            q = q->next;//q指针后移
        }
    }
    if (p == NULL)//当查找到最后一个节点还未查到要删除的编号时，输出ERROR INPUT
        printf("ERROR INPUT\n");
}

//价格查找
void search(S *head)
{
    S *p;//定义指针
    int price1;//定义num1用于输入查找书籍
    printf("输入你要查找的价格:");
    //输入查找编号
    scanf("%d", &price1);
    p = head->next;
    printf("书籍信息\n");
    printf("编号\t书名\t价格\n");
    while (p != NULL)
    {
        if (p->price==price1)//判断是否找到书籍
        {
            //为真时，输出信息
            printf("%s\t%s\t%.2f\n", p->id, p->name, p->price);
            //break;
        }
        p = p->next;//指针后移
    }
    if (p == NULL)//查找到最后一个节点还未查到要的编号时，输出ERROR INPUT
        printf("结束查找\n");
}

//输出链表模块
void print(S *head)
{
    //int i;
    S *p = head->next;
    while (p)//当p不为空的时候执行
    {
        printf("%s\t%s\t%.2f\n", p->id, p->name, p->price);
        //printf("\n");
        p = p->next;//指针后移
    }
}




