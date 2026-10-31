//进制转换（2-36进制）
#include<iostream>
using namespace std;
int n = 0, b = 0, temp = 0, i = 0;
bool fushu = 0;
char s[500];
void itob(int n, char s[], int b) {
	i = 0;
	fushu = 0;
	if (n < 0) {                                          //对负数单独做一下简单处理
		fushu = 1;
		n = -n;
	}
	if (n == 0) {                                        //等于0的情况直接跳出去，以免造成什么其他问题
		return;
	}
	while (n > 0) {
		temp = n % b;                                      //标准的除基取余法，此处取余
		if (temp <= 9) {
			s[i] = temp + '0';                                //9以内的用数字表示
			i++;
		}
		else {
			s[i] = temp - 10 + 'a';                          //9-36:用字母表示
			i++;
		}
		n /= b;                                            //此处除基
	}
}


int main() {
	cin >> n >> b;
	itob(n, s, b);
	if (n == 0) {
		cout << "0";
		return 0;
	}
	if (fushu) {
		cout << "-";                                          //负数在前面加上负号开始输出
	}
	for (int j = i - 1; j >= 0; j--) {                      //根据上方的运算顺序，最后得到的数字应该放在最高位输出
		cout << s[j];
	}
}


