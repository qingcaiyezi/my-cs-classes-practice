//4. 字符串差集 - 副本
【问题描述】
从键盘输入两个字符串A和B（每个字符串内都无重复字符）。求两个字符串的差集，即：将字符串A中与字符串B中相同的字符去掉（大小写无关，即同一字符的大小写认为是相同的字符）。然后按照ASCII码从小到大的顺序输出差集。若差集为空，则输出字符串：NULL。
【输入形式】
先从键盘输入字符串A，然后输入字符串B，每个字符串末尾都有回车换行符，但回车换行符不作为字符串的字符，并且每个字符串不超过50个字符。提示：输入整行数据可以使用gets()函数，使用方法自行搜索。
【输出形式】
按照ASCII码从小到大的顺序输出字符串A减去字符串B的差集。
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string A, B, diff;
bool bijiao(char a, char b) {
	if ((a >= 65) && (a <= 90)) {				          //A为大写
		a += 32;
	}
	if ((b >= 65) && (b <= 90)) {				          //B为大写
		b += 32;
	}
	if (a == b) {
		return 0;								                    //相等的需要消除的返回0，在下面的if内就不会将其放入diff内
	}
	return 1;
}
int main() {
	getline(cin, A);
	getline(cin, B);
	for (int i = 0; i < A.length(); i++) {
		bool keep = 1;									            //每到A的一个字符都先假定可以输出
		for (int j = 0; j < B.length(); j++) {			//这样嵌套循环的作用：将第一重循环定下的A的字符与每个B中的字符进行比较
			if (bijiao(A[i], B[j]) == 0) {				    //开始遍历B，发现有一样的，keep变为0，不将其保留，并且break出去准备换到下一个A
				keep = 0;
				break;
			}
		}
		if (keep == 1) {								            //遍历完B后，判断当下A[i]是否保留，只有keep = 1时，才把要输出的字符存进diff里面，执行完后for到底，准备切换下一个A
			diff += A[i];
		}
	}
	if (diff.empty()) {
		cout << "NULL";
	}
	else {
		sort(diff.begin(), diff.end());
		cout << diff;
	}
	return 0;
}




