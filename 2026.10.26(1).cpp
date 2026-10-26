//P1200，今天不学新知识了，开始刷洛谷的入门题单。
#include<iostream>
#include<string>
using namespace std;
int main() {
    string name_of_star, name_of_group;
    int pais = 1, paig = 1;
    int nos[7] = {0}, nog[7] = {0};
    cin >> name_of_star;
    cin >> name_of_group;
    for (int i = 0; (int)name_of_star[i] != '\0'; i++) {                                        //用 != '\0'是之前用char数组留下的一个习惯，现在直接用length函数即可
        nos[i] = (int)name_of_star[i] - '@';
        pais *= nos[i];                                                                        //写完之后再看发现其实不用开数组，pais *= name_of_star[i] - '@'即可。
    }                                                                                          //(int)显式强制类型转换也没必要，name_of_star[i] - '@'会做隐式转换。
    for (int j = 0; (int)name_of_group[j] != '\0'; j++) {
        nog[j] = (int)name_of_group[j] - '@';
        paig *= nog[j];
    }
    if (paig % 47 == pais % 47) {
        cout << "GO";
    }    else {
        cout << "STAY";
    }
}
    
