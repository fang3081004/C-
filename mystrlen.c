#include<stdio.h>
int mystrlen(char* ch);
int mystrlen(char* ch)
{
	int i = 0;
	while (*ch)//*ch 而非ch
	{
		ch++;
		i++;
	}
	return i;
}

int main(int argc, char *argv[])
{
	char* p = "abcdefg";
	int length;
	length= mystrlen(p);
	printf("%d\n",length);
	system("pause");
	return 0;
}
