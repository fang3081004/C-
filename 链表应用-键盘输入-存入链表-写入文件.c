#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
从键盘输入姓名年龄，把每行的数据按age从大到小的顺序写入一个文件中。 
提示：
(1) 每行的学生信息可用一个结构体进行保存。 
	typedef struct _tag_Student { char name[24]; int age; }Student;
(2) 获取从文件中读取的每一行学生的信息。
	函数原型：int getStudentInfo( Student *stu);
	函数功能：将输入的学生信息保存到一个结构体变量中。
	函数参数：	stu：指向用于保存学生信息的结构体。
(3) 获得的每个学生的信息可用链表进行保存。 
	typedef struct _listNode { Student *stu; struct _listNode *next; }ListNode;
*/

typedef struct _tag_Student 
{   char name[24]; 
	int age; 
}Student;

typedef struct _listNode 
{	Student *stu; 
	struct _listNode *next; 
}ListNode;

int getStudentInfo(char *studentInfo, Student *stu) {
	char nametmp[24];
	int agetmp;
	printf("姓名：");
	scanf("%s", nametmp);
	printf("年龄");
	scanf("%d", &agetmp);
	stu->age = agetmp;
	strcpy(stu->name, nametmp);
	return 0;


}

void insertLinkByAge(ListNode* head,Student* stu) {

	/*if (head == NULL || stu == NULL) {
		puts("参数错误");
		return -1;
	}*/

	ListNode* pPre = head;
	ListNode* pCurrent = head->next;
	while (pCurrent != NULL)
	{
		if (pCurrent->stu->age>stu->age)
		{
			pPre = pCurrent;
			pCurrent = pCurrent->next;
		}
		else
		{
			break;
		}
	}
	
	
	ListNode* newnode = calloc(1, sizeof(ListNode));
	newnode->stu = stu;
	newnode->next = NULL;
	newnode->next = pCurrent;
	pPre->next = newnode;
	
}

printByAge(ListNode* head){
	ListNode* pCurrent = head->next;
	while (pCurrent!=NULL)
	{
		if (pCurrent->stu != NULL)
		{
			printf("姓名：%s 年龄：%d\n", pCurrent->stu->name, pCurrent->stu->age);
			pCurrent = pCurrent->next;
		}
		
	}
}

int writeToFile(ListNode * head, const char * filename) {
	if (head == NULL || filename == NULL) {
		puts("参数错误");
		return -1;
	}
	ListNode* pCurrent = head->next;
	while (pCurrent!=NULL)
	{
		fprintf(filename, "姓名：%s 年龄：%d\n", pCurrent->stu->name, pCurrent->stu->age);
		pCurrent = pCurrent->next;
	}
}


int main(int argc, char *argv[])
{
	ListNode* head = calloc(1, sizeof(ListNode));              //分配头结点
	head->stu = NULL;
	head->next = NULL;

	Student* s1=calloc(1,sizeof(Student));                    //分配一个学生空间
	getStudentInfo("abc",s1);								                  //从键盘输入学生信息
	insertLinkByAge(head,s1);								                  //将新输入的学生按年龄插入到链表
	

	Student* s2 = calloc(1, sizeof(Student));
	getStudentInfo("abc", s2);
	insertLinkByAge(head, s2);
	
	Student* s3 = calloc(1, sizeof(Student));
	getStudentInfo("abc", s3);
	insertLinkByAge(head, s3);
	//printByAge(head);

	//写到文件
	FILE* fp = fopen("student2.txt", "w");
	if (fp==NULL)
	{
		perror("fopen error");
		return;
	}
	writeToFile(head,fp);
	fclose(fp);

	system("pause");
	return 0;
}
