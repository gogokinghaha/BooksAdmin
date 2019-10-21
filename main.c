#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
//�����ṹ�弰���Ա
typedef struct Node
{
    char id[20];//���
    char name[50];//����
    float price;//�۸�
    struct LNode *next;//ָ����
}S;//�ṹ�嶨��ΪS
   //����������
void choose();
void menudisplay(); //�˵�����
S *create();//����������
void input(S *);//�½���Ŀ
void print(S *);//���������
void pop_sort(S *);//����
void insert(S *);//����ڵ㺯��
void del(S *);//ɾ���ڵ㺯��
void search(S *);//�۸����
void textinput(S *);//�ļ�д��
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
        menudisplay();//��ʾ�˵�
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
                search(head);
                break;
            case 7:
                input(head);
                printf("���\t����\t�۸�\n");
                print(head);
                break;
            case 8:
                textinput(head);
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
void menudisplay()
{
    printf("\n\n");
    printf("  ��ӭʹ��ͼ�����ϵͳ\n");
    printf("|----------����--------|\n");
    printf("1.����                 |\n");
    printf("2.���                 |\n");
    printf("3.����                 |\n");
    printf("4.ɾ��                 |\n");
    printf("5.ȡֵ                 |\n");
    printf("6.�۸�����             |\n");
    printf("7.���                 |\n");
    printf("8.�ļ����             |\n");
    printf("0.�˳�����             |\n");
    printf("|----------------------|\n");
    printf("ѡ��(1-8):\n");
}
//��������ģ��
S *create()
{
    S *head, *p, *q;//����ָ��
    int i;
    head = (S *)malloc(sizeof(S));//ͷ�ڵ㿪�ٿռ�
    head->next = NULL;//�ÿ�ͷ�ڵ��ָ����
    printf("�����ɹ�\n");
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
    return head;//�����������ʼ��ַ
}

//�����Ŀ
void input(S *head)
{

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
    return head;//�����������ʼ��ַ


}

//ͨ���ļ��������
void textinput(S *head)
{
    FILE *fp;
    S *p, *q;//����ָ��
    //q = head;//qָ���¼ͷ�ڵ�ĵ�ַ
    p = head->next;//pָ���¼ͷ�ڵ��ָ����ĵ�ַ
	int i = 0;
	int j = 0;
	float PRICE;//�����ļ�������������
	char  NAME[20], ID[20];
	fp = fopen("text.txt","r");//���ļ�
	if(fp == NULL)
    {
        printf("��ȡ�ļ�ʧ��\n");
        exit(0);
    }
    else
    {
        printf("����ļ��ɹ�\n");
    }
    /*if(p == NULL)
    {
        printf("�봴������");
    }*/
    while(p->next != NULL)
    {
        p = p->next;
    }
    while(!feof(fp))
    {
        //fgets(line)
        q = (S *)malloc(sizeof(S));//pָ�뿪�ٿռ�
        //fscanf(fp,"%s %s %f", &ID, &NAME, &PRICE);
        fscanf(fp,"%s %s %f", &q->id, &q->name,&q->price);

        //q->id = ID;
        //q->name = NAME;
        //q->price = PRICE;

        q->next = p->next;
        p->next = q;//�ÿ�p�ڵ��ָ����
        p = q;

        //printf("������������:%s %s %.1f",ID,NAME,PRICE);
    }

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
        printf("����λ�ó�����");
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
void search(S *head)
{
    S *p;//����ָ��
    int price1;//����num1������������鼮
    printf("������Ҫ���ҵļ۸�:");
    //������ұ��
    scanf("%d", &price1);
    p = head->next;
    printf("�鼮��Ϣ\n");
    printf("���\t����\t�۸�\n");
    while (p != NULL)
    {
        if (p->price==price1)//�ж��Ƿ��ҵ��鼮
        {
            //Ϊ��ʱ�������Ϣ
            printf("%s\t%s\t%.2f\n", p->id, p->name, p->price);
            //break;
        }
        p = p->next;//ָ�����
    }
    if (p == NULL)//���ҵ����һ���ڵ㻹δ�鵽Ҫ�ı��ʱ�����ERROR INPUT
        printf("��������\n");
}

//�������ģ��
void print(S *head)
{
    //int i;
    S *p = head->next;
    while (p)//��p��Ϊ�յ�ʱ��ִ��
    {
        printf("%s\t%s\t%.2f\n", p->id, p->name, p->price);
        //printf("\n");
        p = p->next;//ָ�����
    }
}




