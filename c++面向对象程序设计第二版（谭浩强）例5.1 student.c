#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<iostream>
#include<string>

class student {
public:void get_value() {
	cout << "请输入学号 姓名 性别"<<endl;
	cin >> num >> name >> sex;
}
	   void display() {
		   cout << "学号：" << num << endl << "姓名：" << name <<endl<< "性别：" << sex << endl;
	   }
private:int num;
		string name;
		char sex;
};
class student1 :public student {
public:void get_value_1() {
	cout << "请输入年龄 地址" << endl;
	cin >> age >> address;
}
	   void display_1()
	   {
		   display();
		   cout << "年龄："<<age << endl << "地址：" << address << endl;
	   }
private:int age;
		string address;
};

int main(int argc, char *argv[])
{
	//student stu;
	//stu.get_value();
	//stu.display();
	//student1 stu1;
	//stu1.get_value_1();
	//stu1.display_1();
	//system("pause");
	student1 stu1;
	stu1.get_value();
	stu1.get_value_1();
	
	stu1.display_1();
	
	system("pause");
	return 0;
}
