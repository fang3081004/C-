#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<iostream>
#include<string>
template <typename T>
void mysort(T* ch,int n)
{
	
	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (ch[j]<ch[min])
			{
				min = j;
			}
		}
		if (min!=i)
		{
			int tmp = 0;
			tmp = ch[i];
			ch[i] = ch[min];
			ch[min] = tmp;
		}
		
	}
}

template<typename T>
void myprint(T* ch, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << ch[i];
	}
}

int main(int argc, char *argv[])
{
	char tmp[] = "helloworld";
	int num[] = { 4,5,1,2,6,7,8,9,3 };
	int len = sizeof(tmp) / sizeof(char);
	mysort<char>(tmp,len);
	myprint(tmp,len);
	len = sizeof(num) / sizeof(int);
	mysort<int>(num, len);
	myprint(num, len);
	system("pause");
	return 0;
}
