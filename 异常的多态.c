#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<iostream>
#include<string>

class MyException
{
public:
	MyException() {
		cout << "默认构造" << endl;
	};
	MyException(const MyException & e)
	{
		cout << "拷贝构造" << endl;
	}
	~MyException()
	{
		cout << "析构" << endl;
	}
};

void dowork() {
	throw  MyException();//如果throw new MyException();抛出一个指针，下面需用指针捕获
}
int main(int argc, char *argv[])
{
	try {
		dowork();
	}
	//如果上面抛出指针类型的异常，这里需catch(MyException* e)
	//如果这里使用引用捕获异常，则，只调用默认构造函数，不调用拷贝构造函数，析构函数也只调用一次
	catch(MyException e)
	{
		cout << "补货异常！！！！" << endl;
	}
	system("pause");
	return 0;
}
