//题目：小鱼比可爱
#include<iostream>
using namespace std;
int main() {
  int n,a[110];        //100条小鱼，数组空间加十个保险一点。
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];      //循环输入每一个小鱼的可爱程度进数组。
    int num = 0;
    for (int j = i - 1; j >= 1; j--) {    //j作为被比鱼，i为当前鱼，从i左边开始比，即i-1，每比一条往左移一个，即读取数组内j--的数字。由于数组是由i=1开始写入的，故j的循环条件是j>=1
      if ( a[j] < a[i]) {
        num++;
      }
    }
    cout << num << " ";        //比完之后输出，到这里单次循环结束。
  }
return 0;
}
