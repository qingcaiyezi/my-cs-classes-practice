//P5741    本题虽有按照字典序排名字输出的要求，但由于输入的数据已排好，所以不需要单独再排序。若遇到乱序输出，在以下代码前，先写排序函数， 使输入有序，再执行如下命令即可。
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct student {
    string name;
    int chi, mat, eng;
};
student s[1010];                                            //学习结构体及其数组的使用
bool compare(student a, student b) {
    if ((abs(a.chi - b.chi) <= 5)&&(abs(a.mat - b.mat) <= 5)&&(abs(a.eng - b.eng) <= 5)&&(abs((a.chi + a.mat + a.eng) - (b.chi + b.mat + b.eng)) <= 10)) {
        return 1;
    }    else {
        return 0;                                        //布尔函数将比较的过程抽离
    }
}
int main() {
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].name >> s[i].chi >> s[i].mat >> s[i].eng;
    }
    for (int s1 = 1; s1 < n; s1++) {
        for (int s2 = s1 + 1; s2 <= n; s2++) {
            if (compare(s[s1], s[s2])) {
                cout << s[s1].name << " " << s[s2].name << endl;        
            }
        }
    }
}
