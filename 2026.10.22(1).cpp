//P5736，今天开始学习函数与结构体。从今天开始，代码就要写得开始模块化，学会自己写一个单独的函数来解决遇见同样的事情需要反复做的问题，使代码逻辑清晰
#include<iostream>
using namespace std;
int a[110] = {0};
int n = 0;
bool zhishupanduan(int x) {                                //bool型函数内判断是否是质数，是质数返回1否则返回0
    if ((x == 1)||(x == 0)) {
        return 0;
    }
    for (int j = 2; j*j <= x; j++) {
        if (x % j == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int k = 0; k < n; k++) {
        if (zhishupanduan(a[k])) {                        //if(1)时执行，if(0)时跳过
            cout << a[k] << " ";
        }
    }
    return 0;
}
