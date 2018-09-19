#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<iostream>
#include<string>
#include<fstream>
class Person {
public:
	Person(){}
Person(int age,char * na) {
	this->age = age;
	strcpy(this->name ,na);
}
public:int age;
		char name[32];
};

int main(int argc, char *argv[])
{
	//将对象写入文件
	char* filename = "person.txt";
	ofstream ofs(filename, ios::out|ios::binary);
	Person p1(20,"小红");
	Person p2(22, "小明");
	ofs.write((const char*)&p1,sizeof(Person));
	ofs.write((const char*)&p2,sizeof(Person));
	ofs.close();

	//从文件中读取对象
	ifstream ifs(filename, ios::in);
	if (!ifs)
	{
		cout << "文件打开失败" << endl;
	}
	Person p3;
	Person p4;
	ifs.read((char*) &p3,sizeof(Person));
	ifs.read((char*)&p4, sizeof(Person));
	cout << p3.name << p3.age << endl;
	cout << p4.name << p4.age << endl;
	ifs.close();
	system("pause");
	return 0;
}
