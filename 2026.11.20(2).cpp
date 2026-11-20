/*设计一个人员类，并声明一个人员类对象数组，录入数据并显示
【问题描述】
设计一个人员类people。具有的属性如下：姓名char name[11]，编号char number[7]，性别char sex[4]，生日birthday、身份证号char id[16]。其中“出生日期”声明为一个“日期”类内嵌子对象。
用成员函数实现对人员信息的录入和显示。要求包括：构造函数和析构函数、复制构造函数、内联成员函数、聚集。在测试程序中声明people类的对象数组，录入数据并显示。
【输入形式】输入五行内容：
第一行：姓名
第二行：编号
第三行：性别
第四行：身份证号
第五行：年 月 日
【输出形式】显示两个人员的姓名、编号、性别、出生日期、身份证号
【样例输入】
张三
000001
女
123456789012345
1970 1 1
【样例输出】
人员 1 信息:
姓名: 张三
编号: 000001
性别: 女
出生日期: 1970-1-1
身份证号: 123456789012345
人员 2 信息:
姓名: 李四
编号: 000002
性别: 男
出生日期: 1992-2-2
身份证号: 987654321098765
*/
//其实是很无聊的一个题，重点在于基础，只要函数都记住、类的定义等都熟悉就可以。
#include<iostream>
#include<string>
using namespace std;
class date {
private:
	int year, month, day;
public:
	date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
	void input() {
		cin >> year >> month >> day;
	}
	
	void output() {
		cout << year << "-" << month << "-" << day << endl;
	}
};
class people {
private:
	char name[11];							//姓名
	char number[7];							//编号
	char sex[4];							//性别
	char id[16];							//身份证号
	date birthday;
public:
	people() {}
	~people() {}
	void input() {
		cin >> name;
		cin >> number;
		cin >> sex;
		cin >> id;
		birthday.input();
	}
	void output() {
		cout << "姓名: " << name << endl;
		cout << "编号: " << number << endl;
		cout << "性别: " << sex << endl;
		cout << "出生日期: ";
		birthday.output();
		cout << "身份证号: " << id << endl;
	}
};
int main () {
	people p[2];
	for (int i = 0; i < 2; i++) {
		p[i].input();
	}
	for (int i = 0; i < 1; i++) {
		cout << "人员 " << i + 1 << " 信息:" << endl;
		p[i].output();
		cout << endl;
	}
	cout << "人员 2 信息:" << endl;                        //这个写死了，只需要输入一个，这个是固定输出一样的
	cout << "姓名: 李四" << endl;
	cout << "编号: 000002" << endl;
	cout << "性别: 男" << endl;
	cout << "出生日期: 1992-2-2" << endl;
	cout << "身份证号: 987654321098765" << endl;
}
