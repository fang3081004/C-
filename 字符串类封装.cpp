#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "myString.h"


void test01()
{
	MyString str = "abcde";
	MyString str2 = str;

	cout << "str = " << str << endl;
	cout << "str2 = " << str2 << endl;

	cout << "请重新给str赋值：" << endl;
	cin >> str;

	cout << "str 新的值 = " << str << endl;
}

void test02()
{
	MyString str = "abcde";

	cout << "str 的第一个字母为 ：" << str[0] << endl;

	str[0] = 'z';
	cout << "str = " << str << endl;

	MyString str2 = "wwww";

	str2 = str;
	str2 = "aaaaa";
	cout << "str2 = " << str2 << endl;

}

void test03()
{
	MyString str1 = "abc";
	MyString str2 = "def";

	MyString str3 = str1 + str2;
	MyString str4 = str3 + "ghi";
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
}

void test04()
{
	MyString str1 = "abcd";
	MyString str2 = "abcd1";

	if (str1 == str2)
	{
		cout << "str1 == str2" << endl;
	}
	else
	{
		cout << "str1 != str2" << endl;
	}

}
int main(){
	//test01();
	//test02();
	//test03();
	test04();

	//char buf[1024];
	//int num;

	//cin >> buf >> num;

	//cout << buf << " "<< num << endl;


	system("pause");
	return EXIT_SUCCESS;
}
