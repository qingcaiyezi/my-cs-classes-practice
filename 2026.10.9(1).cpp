//题目：数列求和：0.1+0.2+...+(n-1)+n，其中n为不大于100的整数
#include<iostream>
using namespace std;
int main() {
    int n, i, max;
    double ans = 0;        
    cin >> n;
    max = n * 10;        //直接使用double类型浮点数相加容易丢失精度，视题目要求，将数字扩大10倍，进行运算后再缩回，可避免丢失精度问题。
    for (i = 1; i <= max; i++) {        //虽然本题可以采用数学上等差数列求和的方法解答，但今天主要目的是熟悉for循环的使用，故采用此写法。
        ans += i;
    }
    ans *= 0.1;
    cout << ans;
    return 0;
}
