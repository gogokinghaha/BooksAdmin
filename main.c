#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
//�����ṹ�弰���Ա
typedef struct Node
{
    char id[20];//���
    char name[20];//����
    //char author[20];//����
    //int isexsit;//����
    float price;//�۸�
    struct Node *next;//ָ����
}S;//�ṹ�嶨��ΪS
   //����������
void choose();
void menu(); //�˵�����
S *create();//������������
void input(S *);//�½���Ŀ
void print(S *);//�����������
void pop_sort(S *);//����
void insert(S *);//����ڵ㺯��
void del(S *);//ɾ���ڵ㺯��
void search4(S *);//�۸����
void mod(S *);//�޸�ͼ����Ϣ
     //������
int main()
{
    choose();
}
void choose()
{
    S *head;
    int n, a = 1;//n��������ѡ��������ͣ�a����ѭ������-1��ֹ
    while (a>0)
    {
        menu();//��ʾ�˵�
        printf("��ѡ����Ҫִ�еĲ���:");
        scanf("%d", &n);//ѡ�����
        switch (n)//���������ֶ�Ӧ�˵����֣�ͨ��nȷ����������
        {
            case 1://����
                head = create();
                break;
            case 2://���
                //printf("ͼ����ϢΪ(���۸������)\n");
                //pop_sort(head);
                printf("���\t����\t�۸�\n");
                print(head);
                break;
            case 3://����
                insert(head);
                printf("�����\n");
                printf("���\t����\t�۸�\n");
                print(head);
                break;
            case 4://ɾ��
                del(head);
                printf("ɾ����\n");
                printf("���\t����\t�۸�\n");
                print(head);
                break;
            case 5://ȡֵ
                get(head);
                break;
            case 6://�۸����
                search4(head);
                break;
            case 7:
                input(head);
                printf("���\t����\t�۸�\n");
                print(head);
                break;
            default:
                a = -1;//����ѭ������
                break;
        }
    }
}

//�˵�ģ��ֱ����ʾ
void menu()
{
    printf("\n\n");
    printf("\t\t     ��ӭʹ��ͼ�����ϵͳ\n");
    printf("\t\t|--------------����------------|\n");
    printf("\t\t|\t1.����                 |\n");
    printf("\t\t|\t2.���                 |\n");
    printf("\t\t|\t3.����                 |\n");
    printf("\t\t|\t4.ɾ��                 |\n");
    printf("\t\t|\t5.ȡֵ                 |\n");
    printf("\t\t|\t6.�۸�����             |\n");
    printf("\t\t|\t7.����                 |\n");
    printf("\t\t|\t8.�˳�����             |\n");
    printf("\t\t|------------------------------|\n");
    printf("\t\t\tchoice(1-7):\n");
}
//��������ģ��
S *create()
{
    S *head, *p, *q;//����ָ��
    int i;
    head = (S *)malloc(sizeof(S));//ͷ�ڵ㿪�ٿռ�
    head->next = NULL;//�ÿ�ͷ�ڵ��ָ����
    q = head;//qָ���¼ͷ�ڵ�ĵ�ַ
    p = head->next;//pָ���¼ͷ�ڵ��ָ����ĵ�ַ

    int num=1;
    //scanf("%d", &num);
    while (num != 0)//�����鼮�������Ϊ��ֹͣѭ��
    {
        p = (S *)malloc(sizeof(S));//pָ�뿪�ٿռ�
           //�������Ա
        //p->num = num;
        printf("��������ı�ţ������Լ��۸�,�ÿո����\n");
        scanf("%s %s %f", &p->id, &p->name,&p->price);
        p->next = NULL;//�ÿ�p�ڵ��ָ����
        q->next = p;//p��q�ڵ�����
        q = p;//qָ�����
        printf("����0��������,����1��������\n");
        scanf("%d", &num);
    }
    return head;//������������ʼ��ַ
}

void input(S *head)
{
    /*int i=0, flag = 1;//flagʵ���ж�ָ���Ƿ񵽴����һ���ڵ�
    S *p, *q, *r; //����ָ����ڲ������
    r = (S *)malloc(sizeof(S));//Ϊr���ٿռ�
    printf("ѡ��Ҫ���ӵ��鱾��Ϣ,������ţ��������۸񣬾��ÿո����\n");
    scanf("%s %s %f", r->id, r->name, r->price);
    p = head;//qָ���¼ͷ�ڵ�ĵ�ַ
    q = head->next;
    while(q != NULL)
    {
        p = p->next;//pָ�����
        q = q->next;//qָ�����
    }
    q->next = r;
    r->next = NULL;*/

    S *p, *q;//����ָ��
    //q = head;//qָ���¼ͷ�ڵ�ĵ�ַ
    p = head->next;//pָ���¼ͷ�ڵ��ָ����ĵ�ַ
    int i = 0;
    while(p->next != NULL)
    {
        p = p->next;
    }
    int num=1;
    //scanf("%d", &num);
    while (num != 0)//�����鼮�������Ϊ��ֹͣѭ��
    {
        q = (S *)malloc(sizeof(S));//pָ�뿪�ٿռ�
           //�������Ա
        //p->num = num;
        printf("��������ı�ţ������Լ��۸�,�ÿո����\n");
        scanf("%s %s %f", &q->id, &q->name,&q->price);
        q->next = p->next;
        p->next = q;//�ÿ�p�ڵ��ָ����
        //q = p;//p��q�ڵ�����

        num = 0;
        //q = p;//qָ�����
        //printf("����0��������,����1��������\n");
        //scanf("%d", &num);
    }
    return head;//������������ʼ��ַ


}

//����ڵ�ģ��
void insert(S *head)
{
    int i=0, num, flag = 1;//flagʵ���ж�ָ���Ƿ񵽴����һ���ڵ�
    S *p, *q, *r; //����ָ����ڲ������
    r = (S *)malloc(sizeof(S));//Ϊr���ٿռ�
    q = head;//qָ���¼ͷ�ڵ�ĵ�ַ

     //printf("please input a book's messages:\n");
    printf("ѡ��Ҫ�����λ�ú��鱾��Ϣ,������ţ��������۸񣬾��ÿո����\n");
    scanf("%d %s %s %f", &num, &r->id, &r->name, &r->price);
    while(i < num-1 ){
        q = q->next;
        i++;
    }
    if(q == NULL)
    {
        printf("����λ�ó�������");
    }else
    {
        r->next = q->next;
        q->next = r;
    }

    /*if(!q || i > num - 1){
        printf("����ʧ��");
    }else{
        r->next = q->next;
        q->next = r;
    }*/

}

//ȡֵ
void get(S *head)
{
    S *p, *q;//����ָ��
    int i = 0;
    int b;//���������Ų���ɾ��
    p = head;//p��¼ͷ�ڵ�ĵ�ַ
    q = head->next;//q��¼ͷ�ڵ��ָ����ĵ�ַ
    printf("������Ҫ��ȡ��ͼ��λ��:");
    //������
    scanf("%d", &b);
    while (q != NULL)//q��Ϊ��ʱִ��ѭ��
    {
        if (i == (b-1))//�ж��Ƿ��ҵ�����ı��
        {
            //Ϊ��ʱ
            printf("�鼮��Ϣ\n");
            printf("���\t����\t�۸�\n");
            printf("%s\t%s\t%.2f\n", p->id, p->name, p->price);
            break;
        }
        else
        {
            i++;
               //�ж�Ϊ��ʱ
            p = p->next;//pָ�����
            q = q->next;//qָ�����
        }
    }
    if (p == NULL)//�����ҵ����һ���ڵ㻹δ�鵽Ҫɾ���ı��ʱ�����ERROR INPUT
    printf("ERROR INPUT\n");
}

//ɾ���ڵ�ģ��
void del(S *head)
{
    S *p, *q;//����ָ��
    int i = 0;
    int b;//���������Ų���ɾ��
    p = head;//p��¼ͷ�ڵ�ĵ�ַ
    q = head->next;//q��¼ͷ�ڵ��ָ����ĵ�ַ
    printf("������Ҫɾ����ͼ��λ��:");
    //������
    scanf("%d", &b);
    while (q != NULL)//q��Ϊ��ʱִ��ѭ��
    {
        if (i == (b-1))//�ж��Ƿ��ҵ�����ı��
      //Ϊ��ʱ
        {
            p->next = q->next;//�Ͽ�q�ڵ�
            free(q);//�ͷ�q�ڵ�neicun
            q = NULL; //�ÿ�qָ���ֹ����Ұָ��
        }
        else
        {
            i++;
            //�ж�Ϊ��ʱ
            p = p->next;//pָ�����
            q = q->next;//qָ�����
        }
    }
    if (p == NULL)//�����ҵ����һ���ڵ㻹δ�鵽Ҫɾ���ı��ʱ�����ERROR INPUT
        printf("ERROR INPUT\n");
}

//�۸����
void search4(S *head)
{
    S *p;//����ָ��
    int price1;//����num1������������鼮
    printf("������Ҫ���ҵļ۸�:");
    //������ұ��
    scanf("%d", &price1);
    p = head->next;
    while (p != NULL)
    {
        if (p->price==price1)//�ж��Ƿ��ҵ��鼮
        {
            //Ϊ��ʱ�������Ϣ
            printf("�鼮��Ϣ\n");
            printf("���\t����\t�۸�\n");
            printf("%s\t%s\t%.2f\n", p->id, p->name, p->price);
            break;
        }
        else//Ϊ��ʱ
            p = p->next;//ָ�����
    }
    if (p == NULL)//���ҵ����һ���ڵ㻹δ�鵽Ҫ�ı��ʱ�����ERROR INPUT
        printf("ERROR INPUT\n");
}


//�޸���Ϣģ��
/*void mod(S *head)
{
 S *p;//����ָ��
 int num1, num2,isexsit1;//����num1������������鼮�޸���Ϣ,num2�����޸�
 char name1[20], author1[20];
 float price1;
 printf("input the book's num you are modification:");
 //����Ҫ�޸ĵ�ͼ����
 scanf("%d", &num1);
 p = head->next;
 while (p != NULL)
 {
  if (p->num == num1)//�ж��Ƿ��ҵ��鼮
  {
   printf("please input book's num,name,author,isexsit and price again\n");
   //Ϊ��ʱ������ͼ����Ϣ
   scanf("%d %s %s %d %f", &num2, name1, author1, &isexsit1,&price1);
   p->num = num2;
   strcpy(p->name, name1);
   strcpy(p->author, author1);
   p->isexsit = isexsit1;
   p->price = price1;
   break;
  }
  else
   //Ϊ��ʱ
   p = p->next;//ָ�����
 }
 if (p == NULL)//���ҵ����һ���ڵ㻹δ�鵽Ҫ�ı��ʱ�����ERROR INPUT
  printf("ERROR INPUT\n");
}
void pop_sort(S *head)   //����ð������
{
 //������û���޸�ͷ�ڵ�ָ��ֵ��ֻ���޸�ָ������head->next��ֵ
 S *pre, *p, *tail, *temp;
 tail = NULL;
 pre = head;
 while ((head->next->next) != tail)//(head->next)!=tailͬ������ ����ִ�����һ�����Ƚ�
 {
  p = head->next;
  pre = head;
  while (p->next != tail)
  {
   if ((p->price)>(p->next->price))
   {
    pre->next = p->next; //�����ڵ㷽��
    temp = p->next->next;
    p->next->next = p;
    p->next = temp;
    p = pre->next;  //p����һ���ڵ�
   }
   p = p->next;  //p��ǰ��һ���ڵ�
   pre = pre->next;
  }
  tail = p;
 }
}*/
//�������ģ��
void print(S *head)
{
    int i;
    S *p = head->next;
    while (p)//��p��Ϊ�յ�ʱ��ִ��
    {
        printf("%s\t%s\t%.2f\n", p->id, p->name, p->price);
        //printf("\n");
        p = p->next;//ָ�����
    }
}