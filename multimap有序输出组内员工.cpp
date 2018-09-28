#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<iostream>
#include<string>
#include<map>
#include<vector>
class Worker {
public:Worker(int a,string n) {
	this->age = a;
	this->name = n;
}
       int age;
	   string name;

};
void creatWorker(vector<Worker>&v) {
	string nameseed = "ABCDEFGHI";
	for (int i = 0; i < 9; i++)
	{
		string name="";
		name += nameseed[i];
		int age=rand() % 100;
		Worker tmpw(age, name);
		v.push_back(tmpw);
	}
}
void setGroup(vector<Worker>&v,multimap<int,Worker>&wo) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int tmpDepno=rand() % 3;
		wo.insert(make_pair(tmpDepno, (*it)));
	}
}

void showGroup(multimap<int, Worker>&wo) {
	multimap<int, Worker>::iterator pos=wo.find(0);
	int count=wo.count(0);
	int index = 0;
	cout << "分组0：" << endl;
	//这样连续就可以输出每个部门的全部人员，因为multimap是有序的！
	for (; pos!=wo.end(),index<count;index++, pos++)
	{
		
			cout << (*pos).second.name << (*pos).second.age << endl;
	}
	pos = wo.find(1);
	count = wo.count(1);
	index = 0;
	cout << "分组1：" << endl;
	//这样连续就可以输出每个部门的全部人员，因为multimap是有序的！
	for (; pos != wo.end(), index<count; index++, pos++)
	{

		cout << (*pos).second.name << (*pos).second.age << endl;
	}

	pos = wo.find(2);
	count = wo.count(2);
	index = 0;
	cout << "分组2：" << endl;
	//这样连续就可以输出每个部门的全部人员，因为multimap是有序的！
	for (; pos != wo.end(), index<count; index++, pos++)
	{

		cout << (*pos).second.name << (*pos).second.age << endl;
	}
}


int main(int argc, char *argv[])
{
	vector<Worker>v;
	creatWorker(v);
	for (vector<Worker>::iterator it = v.begin(); it!=v.end(); it++)
	{
		cout << (*it).name << (*it).age << endl;
	}
	multimap<int, Worker>m;
	setGroup(v, m);
	showGroup(m);
	system("pause");
	return 0;
}
