//高精度加法
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string A, B;
    int a[505] = { 0 }, b[505] = { 0 }, c[505] = { 0 };
    cin >> A >> B;
    int len_total = max(A.length(), B.length());          //初步判断在不进最后一位的时候输出有多长
    for (int i = 0, j = A.length() - 1; i < A.length(); i++, j--) {
        a[j] = A[i] - '0';                               //从左往右，A的最左边是最高位，计算的时候最后用
    }
    for (int i = 0, j = B.length() - 1; i < B.length(); i++, j--) {
        b[j] = B[i] - '0';                                //从左往右，B的最左边是最高位，计算的时候最后用
    }
    for (int i = 0; i < len_total; i++) {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / 10;
        c[i] %= 10;
    }
    if (c[len_total] != 0) {                            //判断多出来的那一位是否不为零（即是否被进位），如果进位了，则从比原先算出来的长度多一个的位置开始输出
        for (int i = len_total; i >= 0; i--) {          
            cout << c[i];
        }
        return 0;
    }
    for (int i = len_total - 1; i >= 0; i--) {
        cout << c[i];
    }
    return 0;
}


