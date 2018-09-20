#pragma once
#define MAXSIZE 10
#define ElementType int
typedef struct {
	int data[MAXSIZE];
	int length;
}SqList;

void swap(SqList* list, int i, int j) {
	int tmp = list->data[i];
	list->data[i] = list->data[j];
	list->data[j] = tmp;
}
void insertSqList(SqList* list, int pos, ElementType e) {
	if (list->length==0)
	{
		list->data[0] = e;
		list->length++;
	}
	if (pos<0||pos>list->length)
	{
		cout << "位置越界,改为尾插" << endl;
		pos = list->length;;
	}
	if (list->length==MAXSIZE)
	{
		cout << "顺序表已满" << endl;
	}
	for (int i = list->length-1; i >= pos; i--)
	{
		list->data[i + 1] = list->data[i];
	}
	list->data[pos] = e;
	list->length++;

}
void printSqList(SqList* list) {
	if (list==NULL)
	{
		return;
	}
	for (int i = 0; i < list->length-1; i++)
	{
		printf("%d ",list->data[i]);
	}
	printf("\n");
}
