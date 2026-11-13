P1044栈
#include<iostream>
#include<cstring>
using namespace std;

long long ways[25][25] = { 0 };                              //数组记录由i开始至j结束的区间一共有多少种情况

int main() {
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n + 1; i++) {                //这个空区间是基础元素，初始化为1
        ways[i][i - 1] = 1; 
    }
          //接下来是区间dp的骨架，需要熟练掌握
    for (int len = 1; len <= n; len++) {                      //最外层：区间长度循环
        for (int i = 1; i + len - 1 <= n; i++) {              //第二层：遍历区间起点，通过区间长度获得区间终点
            int j = i + len - 1;
            for (int k = i; k <= j; k++) {                    //第三层：遍历区间中的分割值，这个区间的所有情况遵循如下公式：一个区间的所有情况是不同分割值产生的情况之和，而单个分割值产生的情况是由其左边产生的情况乘右边产生的情况得到的
                ways[i][j] += ways[i][k-1] * ways[k+1][j];
            }
        }
    }

    cout << ways[1][n];                                    //输出题目要求：从1到n区间所有的情况，与数组定义吻合。
    return 0;
}
