//P2437蜜蜂路线 高精度斐波那契
#include<iostream>
using namespace std;

int m, n;
int a[500] = { 0 }, b[500] = { 0 }, c[500] = { 0 };

void add(int a[], int b[], int c[]) {                //高精加模板
    for (int j = 0; j < 499; j++) {
        c[j] += a[j] + b[j];
    }
    for (int j = 0; j < 499; j++) {
        if (c[j] >= 10) {
            c[j + 1] += c[j] / 10;
            c[j] %= 10;
        }
    }
}

int main() {
    cin >> m >> n;

    if (m == n || m + 1 == n) {
        cout << 1;
        return 0;
    }

    a[0] = 1; 
    b[0] = 2;                     //起点条件

    for (int i = 1; i <= n - m - 2; i++) {              //从m到n一共需要走n-m-2步
        for (int j = 0; j < 499; j++) c[j] = 0;         //运算之前先初始化c[]当前位数组

        add(a, b, c);

        for (int j = 0; j < 499; j++) {
            a[j] = b[j];
            b[j] = c[j];                                //滚动更新变量
        }
    }
    int len = 0;
    for (int j = 499; j >= 0; j--) {                    //高位判零找最高位
        if (b[j] > 0) {
            len = j;
            break;
        }
    }

    for (int j = len; j >= 0; j--) {
        cout << b[j];
    }

    return 0;
}
