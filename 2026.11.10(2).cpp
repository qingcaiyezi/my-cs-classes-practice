//P1059明明的随机数
//此题学习STL中的set
#include<iostream>
#include<set>
using namespace std;
int main() {
    set<int> s;                        //定义set集合
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s.insert(x);                    //把数字放入集合中的方法
    }
    cout << s.size() << endl;
    for (int j : s) {                    //遍历输出需要用到范围for循环
        cout << j << " ";
    }
}
