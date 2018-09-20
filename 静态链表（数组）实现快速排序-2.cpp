#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<iostream>
#include<string>
#include"顺序表结构.h"

int partition(SqList* list,int low,int high) {
	int pivotkey = list->data[low];
	while (low<high)
	{
		while (low<high&&list->data[high]>pivotkey)
		{
			high--;
		}
		swap(list,low,high);
		while (low<high&&list->data[low]<pivotkey)
		{
			low++;
		}
		swap(list, low, high);
	}
	return low;

}
//简单快速排序
void quickSort(SqList*list,int low,int high) {
	int pivot;
	if (low<high)
	{
		pivot = partition(list, low, high);
		quickSort(list, low, pivot - 1);
		quickSort(list, pivot+1, high);
	}
}
SqList* initSqList() {
	SqList* list2=(SqList*)calloc(1,sizeof(SqList));
	list2->length = 0;
	insertSqList(list2, 0, 5);
	insertSqList(list2, 1, 1);
	insertSqList(list2, 2, 9);
	insertSqList(list2, 3, 3);
	insertSqList(list2, 4, 7);
	insertSqList(list2, 5, 4);
	insertSqList(list2, 6, 8);
	insertSqList(list2, 7, 6);
	insertSqList(list2, 8, 2);
	return list2;
}
int main(int argc, char *argv[])
{
	
	SqList* list=initSqList();
	printSqList(list);
	quickSort(list, 0, 8);
	printSqList(list);
	system("pause");
	return 0;
}
