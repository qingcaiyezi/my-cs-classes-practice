//P1464 递推函数，记忆化搜索
#include<iostream>

using namespace std;

long long a = 0, b = 0, c = 0;
long long ans = 0;
long long temp[25][25][25] = { 0 };
bool o[25][25][25] = { 0 };

long long w(long long a, long long b, long long c) {
	if ((a <= 0) || (b <= 0) || (c <= 0))	return 1;
	else if ((a > 20) || (b > 20) || (c > 20))	return w(20, 20, 20);

	if (o[a][b][c])  return temp[a][b][c];

	o[a][b][c] = true;                                                                          //这里体现了记忆化：如果某个a.b.c已经算过，则将其值抄送来直接用，不进行下一次递推，是节省时间的重要办法  
	
	if (a < b && b < c) {
		ans = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		ans = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}

	temp[a][b][c] = ans;
	return ans;

}




int main() {
	while (cin >> a >> b >> c) {
		if ((a == -1) && (b == -1) && (c == -1)) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
	}
}
