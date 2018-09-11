#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	void* data;
	struct Node* next;
}Node,*NodePtr;
typedef struct Link {
	Node head;
	int size;

}Link;

Link* initLink() {
	Link* link=malloc(sizeof(Link));
	link->head.data = NULL;
	link->head.next = NULL;
	link->size = 0;
	return link;

}

insertLink(Link* link, void* data, int pos) {
	if (link==NULL)
	{
		return;
	}
	if (data==NULL)
	{
		return;
	}
	if (pos<0||pos>link->size-1)
	{
		pos = link->size;
	}
	NodePtr pCurrent = &link->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	NodePtr newnode=malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = pCurrent->next;

	pCurrent->next = newnode;
	link->size++;

}

void printLink(Link* link, void(*fun)(void*)) {
	if (link==NULL)
	{
		return;
	}
	NodePtr pCurrent = link->head.next;
	for (int i = 0; i <link->size ; i++)
	{
		fun(pCurrent->data);
		pCurrent = pCurrent->next;
	}

}
typedef struct Student {
	int stuno;
	char name[32];
} Student;
myprint(void* data) {
	Student* stu1 = data;
	printf("学号：%d  姓名：%s\n",stu1->stuno,stu1->name);
}
void delNode(Link* link, int pos) {
	if (link == NULL)
	{
		return;
	}
	NodePtr pCurrent = &link->head;
	NodePtr pDel = pCurrent;
	for (int i = 1; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	link->size--;

}
void test20180912Link() {
	Student s1 = { 1,"韩梅梅" };
	Student s2 = { 2,"李雷雷" };
	Student s3 = { 3,"小明" };
	Student s4 = { 4,"小红" };
	Student s5 = { 5,"小亮" };
	puts("------");
	Link* newlink=initLink();
	insertLink(newlink, &s1, 0);
	insertLink(newlink, &s2, -1);
	insertLink(newlink, &s3, 0);
	insertLink(newlink, &s4, 1);
	insertLink(newlink, &s5, 0);
	printLink(newlink, myprint);
	delNode(newlink,5);
	printLink(newlink, myprint);
}



int main(int argc, char *argv[])
{
	test20180912Link();
	
	system("pause");
	return 0;
}
