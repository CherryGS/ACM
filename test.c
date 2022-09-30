#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *link;
}Lnode, *LinkList;

void InserAtHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	L = (LinkList)malloc(sizeof(Lnode));
	(*L)->data = 0;
	L->link = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Lnode));
		scanf("%d", *p->data);
		p->link = L->link;
		L->link = p;
	}
}


void InserAtTail(LinkList *L, int m)
{
	LinkList s, p;
	int i;
	L = (LinkList)malloc(sizeof(Lnode));
	L->data = 0;
	L->link = NULL;
	p = L;
	for (i = 0; i < m; i++)
	{
		s = (LinkList)malloc(sizeof(Lnode));
		scanf("%d", *s->data);
		s->link = NULL;
		p->link = s;
		p = s;
	}
}


void PrintList(LinkList L)
{
	printf("H");
	LinkList p = L->link;
	while (p != NULL)
	{
		printf("->%d", p->data);
		p = p->link;
	}

}





void ReverseList(LinkList L)
{
	LinkList p = L->link, q = L->link->link, u;
	p->link = NULL;
	while (q)
	{
		u = q->link;
		q->link = L->link;
		L->link = q;
		q = u;
	}
}


void MergeList(LinkList La, LinkList Lb, LinkList *Lc)
{
	LinkList p = La->link, q = Lb->link, u = La;
	Lc = u;
	while (p&&q)
	{
		if (p->data <= q->data)
		{
			u->link = p;
			u = p;
			p = p->link;
		}
		else
		{
			u->link = q;
			u = q;
			q = q->link;
		}
	}
	u->link = p ? p : q;
}


void DelOdd(LinkList L)
{
	LinkList p = L->link, q = L, s;
	while (p)
	{
		if (p->data % 2 == 1)
		{
			q->link = p->link;
			s = p;
			p = q->link;
			free(s);
		}
		else {
			q = p;
			p = p->link;
		}
	}
}


int main()
{
	int n, m;
	LinkList La, Lb, Lc;
	printf("请输入La数据个数并升序输入数据");
	scanf("%d", &n);
	InserAtHead(La, n);
	PrintList(La);
	printf("\n请输入Lb数据个数并升序输入数据");
	scanf("%d", &m);
	InserAtTail(Lb, m);
	PrintList(Lb);
	printf("\n逆置后的La为:");
	ReverseList(La);
	PrintList(La);
	printf("\n合成的Lc为:");
	MergeList(La, Lb, Lc);
	PrintList(Lc);
	printf("\n删除奇数项后的Lc为:");
	DelOdd(Lc);
	PrintList(Lc);



}