//P1914简易版凯撒密码
#include<iostream>
using namespace std;
int main() {
    char s[55];
    int n = 0;
    cin >> n;
    cin >> s;
    for (int i = 0; s[i] != '\0'; i++) {             //循环条件：读到字符串终止符号就结束，也可以在最后写if break或死循环
        putchar((s[i] - 'a' + n) % 26 + 'a');        //对于z的下一个字母是a的理解。由s[i] - 'a'得出原字母与
    }                                                //a的距离，再加上n得到新位置。模26是为了保持所有位置
    return 0;                                        //都在a-z的范围内
}                                                    //putchar比cout会更快一点
