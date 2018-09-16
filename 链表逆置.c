#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//定义一个学生信息节点
typedef struct stu
{
	//数据域
	int num;
	char name[64];
	float score;

	//指针域
	struct stu *next;
}STU;

//头插法，没有头结点
STU * insert_link(STU * head, STU tmp)
{
	//分配堆区空间
	STU* stutmp = calloc(1, sizeof(STU));
	*stutmp = tmp;
	//指向空
	stutmp->next = NULL;

	//头插
	if (head == NULL)
	{
		head = stutmp;
		return head;
	}
	else
	{
		stutmp->next = head;
		head = stutmp;
		return head;
	}
}
//遍历链表
void printfLink(STU * head)
{
	if (head == NULL)
	{
		printf("链表不存在");
		return;
	}
	STU* pCurrent = head;
	while (pCurrent != NULL)
	{
		printf("姓名：%s 分数：%f\n", pCurrent->name, pCurrent->score);
		pCurrent = pCurrent->next;//经常忘记移动指针
	}
}

STU * deleteLink(STU * head, float score)
{
	return NULL;
}

STU * freeLink(STU * head)
{
	return NULL;
}
//不带头结点，第一个结点就是带数据的结点
//与带头结点的略有区别
STU * reverseLink(STU * head)  
{
	if (head == NULL)
	{
		return;
	}
	STU *pre, *pcurrent, *pNext;

	pcurrent = head;       //当前结点
	//pNext = pcurrent->next;//下一结点
	pre = NULL;            //前一结点
	while (pcurrent != NULL)//如果当前结点不为空
	{
		pNext = pcurrent->next;//下一个结点指向
		pcurrent->next = pre;	//
		pre = pcurrent;			//
		pcurrent = pNext;		//
	}
	
	head = pre;
	return head;
}

STU* reverseLink2(STU *head)
{
	//判断链表是否存在
	if (head == NULL)
	{
		printf("链表不存在\n");
		return head;
	}
	else
	{
		STU *pf = NULL;
		STU *pb = head;//当前结点
		STU *pn = pb->next;//下一个结点

		while (pn != NULL)
		{
			pb->next = pf;//当前结点的指针指向前一结点
			pf = pb;		//前一个结点指向当前结点
			pb = pn;		//当前结点指向下一个结点
			pn = pn->next;	//下一个结点指针向后移动
		}

		//最后一步链接
		pb->next = pf;
		//改变head指针
		head = pb;
		printf("链表成功翻转\n");
	}

	return head;
}
int main(int argc, char *argv[])
{
	STU *s1 = calloc(1, sizeof(STU));
	strcpy(s1->name, "韩梅梅");
	s1->next = NULL;
	s1->num = 1;
	s1->score = 99.0;
	STU *s2 = calloc(1, sizeof(STU));
	strcpy(s2->name, "李雷雷");
	s2->next = NULL;
	s2->num = 2;
	s2->score = 70;
	STU *s3 = calloc(1, sizeof(STU));
	strcpy(s3->name, "小明");
	s3->next = NULL;
	s3->num = 3;
	s3->score = 89.5;
	STU*head = NULL;
	head = insert_link(head, *s1);
	head = insert_link(head, *s2);
	head = insert_link(head, *s3);
	printfLink(head);
	head=reverseLink(head);
	printfLink(head);

	system("pause");
	return 0;
}
