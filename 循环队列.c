#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#define MAX 50
typedef int QElemType;

typedef struct {
	QElemType data[MAX];
	int front;
	int rear;
}SeQueue;
//因为初始化的时候需要分配堆区空间，返回的是地址，故形参为指针
Status InitQueue(SeQueue* sq) {
	sq->front = 0;
	sq->rear = 0;
	return OK;
}
//返回队列长度
int QueueLength(SeQueue* sq) {
	return (sq->rear - sq->front + MAX) % MAX;
}
//入队
Status EnQueue(SeQueue* sq,QElemType e) {
	if (sq->front==(sq->rear+1)%MAX)
	{
		return ERROR;
	}
	sq->data[sq->rear] = e;
	sq->rear=(sq->rear + 1) % MAX;
}
//出队

Status DeQueue(SeQueue* sq,QElemType* e) {
	if (sq->front==sq->rear)
	{
		return ERROR;
	}
	*e = sq->data[sq->front];
	sq->front = (sq->front + 1) % MAX;
}
void testSeQueue() {
	SeQueue* sequeue=calloc(1, sizeof(SeQueue));
	InitQueue(sequeue);
	EnQueue(sequeue, 3);
	EnQueue(sequeue, 4);
	EnQueue(sequeue, 5);
	EnQueue(sequeue, 6);
	EnQueue(sequeue, 7);
	EnQueue(sequeue, 8);
	int len = QueueLength(sequeue);
	
	for (int  i = 0; i < len; i++)
	{
		int e;
		DeQueue(sequeue, &e);
		printf("%d ", e);
	}
	
}
void main() {
	testSeQueue();
	system("pause");
}
