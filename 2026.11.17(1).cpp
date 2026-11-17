//P1928外星密码 递归
#include<iostream>
#include<string>
using namespace std;
string expand() {
	string s = "", X;                     //X用于拼当次重复产生的子串,s用于记住当前次处理应该返回的总结果（注意，一定要把s定义在函数里，这样在不同次的递归中，每一个s才不会互相干扰）
	char c;                               //临时存入读入的单个字符
	int D;                                //重复次数
	while (cin >> c) {                    //单字符读入
		if (c == '[') {                     //如果读入'['，则说明要开始一次递归，准备事项如下：
			cin >> D;                         //读入重复次数
			X = expand();                     //将要重复的部分开始递归，进入函数头
			while (D--) s += X;               //X递归完成之后，将每一次的X按重复次数拼到s上
		}
		else if (c == ']')                  //读入']'代表结束了，将拼接完成的s返回至递归的上一次
			return s;
		else s += c;                        //如果读入的是个普通字符，直接拼上去
	}
	return s;                             //while循环结束，即输入结束后，将总结果即拼好的完整的s返回main中
}
int main() {
	cout << expand();                     //主函数接收递归函数返回的的总输出结果并输出
	return 0;
}
