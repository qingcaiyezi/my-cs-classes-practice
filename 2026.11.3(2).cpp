//P1328生活大爆炸版石头剪刀布
//这道题其实本身没有很多思维上的难度，主要需要细心。
#include<iostream>
#include<string>
using namespace std;
string a[205], b[205];
string A, B;
int pst_A = 0, pst_B = 0;
void function(char n, char m) {
	if (n == m) {
		return;
	}
	if ((n == '0') && ((m == '2') || (m == '3'))) {              //胜利条件不要漏
		pst_A++;
		return;
	}
	if ((n == '1') && ((m == '3')||(m == '0'))) {
		pst_A++;
		return;
	}
	if ((n == '2') && ((m == '4')||(m == '1'))) {
		pst_A++;
		return;
	}
	if ((n == '3') && ((m == '4')||(m == '2'))) {
		pst_A++;
		return;
	}
	if ((n == '4') && (m == '0' || m == '1')) {
		pst_A++;
		return;
	}
	pst_B++;
	return;
}

int main() {
	int N = 0, NA = 0, NB = 0;
	cin >> N >> NA >> NB;
	for (int n = 0; n < NA; n++) {                    //这里记录状况的方法比较暴力，可以取模优化，输入即判断，不需要开很大的数组。
		cin >> a[n];                                    //以后也会遇到很多这样输入即判断，不存下来的优化，需要记住
		A += a[n];
	}
	for (int m = 0; m < NB; m++) {
		cin >> b[m];
		B += b[m];
	}
	int complete_times_A = N / NA;
	int complete_times_B = N / NB;
	int remain_A = N - complete_times_A * NA;
	int remain_B = N - complete_times_B * NB;        //这里有更简单的算法（取余），可以优化
	string OA = A;
	for (int i = 1; i < complete_times_A; i++) {		//次数循环，将完整的加完
		A += OA;                                      //注意此处，不能简单的A += A，会将增加过后的A变成因子，造成指数型增长！
	}
	string OB = B;
	for (int i = 1; i < complete_times_B; i++) {		//次数循环，将完整的加完
		B += OB;
	}
	for (int i = 0; i < remain_A; i++) {			//将余下的加上
		A += a[i];
	}
	for (int i = 0; i < remain_B; i++) {			//将余下的加上
		B += b[i];
	}
	for (int i = 0; i < N; i++) {
		function(A[i], B[i]);
	}
	cout << pst_A << " " << pst_B;
}
