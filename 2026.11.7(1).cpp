//P1067 多项式输出
//该题特别考察细心程度，要写好几个if else判断条件
#include<iostream>
using namespace std;
int main() {
	int xs_mi[105] = { 0 };				//下标为幂，xs_mi[1]记的是x的1次方的系数。
	int n = 0;
	cin >> n;
	for (int i = n; i >= 0; i--) {
		cin >> xs_mi[i];
	}
	bool first = true;
	for (int j = n; j >= 1; j--) {
		if (xs_mi[j] == 0) continue;
		if (xs_mi[j] < 0) {
			if (xs_mi[j] != -1) cout << xs_mi[j] << "x";
			if (xs_mi[j] == -1) cout << "-x";
			if (j != 1) {
				cout << "^" << j;
			}
		}
		else if (xs_mi[j] > 0) {
			if (!first) {
				if (xs_mi[j] != 1) cout << "+" << xs_mi[j] << "x";
				if (xs_mi[j] == 1) cout << "+x";
				if (j != 1) {
					cout << "^" << j;
				}
			}
			if (first) {
				if (xs_mi[j] != 1) cout << xs_mi[j] << "x";
				if (xs_mi[j] == 1) cout << "x";
				if (j != 1) {
					cout << "^" << j;
				}
			}
		}
	first = false;
	}
	if (xs_mi[0] < 0) {
		cout << xs_mi[0];
		return 0;
	}
	if (xs_mi[0] > 0) {
		if (!first) cout << "+" << xs_mi[0];
		else cout << xs_mi[0];
		return 0;
	}
	if (xs_mi[0] == 0) {
		return 0;
	}
}
