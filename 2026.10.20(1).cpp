//P1125笨小猴
#include<iostream>
using namespace std;
int main() {
    char word[110];                                                    //装单词
    int times[25] = {0};                                               //这个就特别一点，用times[0]记录a出现的次数，times[1]记录b出现的次数，这种方法要记下来，以后可能常用
    int maxn = 0, minn = 110; 
    cin >> word;
    for (int i = 0; word[i] != '\0'; i++) {
        times[word[i] - 'a']++;                                        //times里面下标记为word[i] - 'a'就体现了“用times[0]记录a出现的次数”
    }
    for (int j = 0; j <= 25; j++) {                                    //记录最大最小值常用的“打擂台”方法，现在已经熟悉并可熟练运用
        if (times[j] >= 1) {                                          //记得一定要把>=1的条件加上，这样最大最小值就不会跑去统计根本没有出现过的字母，导致最小值恒为0
            if (times[j] <= minn) {
                minn = times[j];
            }
            if (times[j] >= maxn) {
                maxn = times[j];
            }
        }
    }
    int cha = maxn - minn;
    for (int k = 2; k*k <= cha; k++) {                                //判断质数（一定是从2开始！！）
        if (cha % k == 0) {
            cout << "No Answer" << endl;
            cout << 0;
            return 0;                                                  //判完直接return 0 结束即可
        }
    }
    if ((cha == 1)||(cha == 0)) {                                      //1和0单独判断，不揉在上面，可以降低难度
        cout << "No Answer" << endl;
        cout << 0;
        return 0;
    }
    cout << "Lucky Word" << endl;                                      //符合上面两种情况都已经return 0退出了，这个cout写在最外层就不怕被干扰，且不需要再额外判断什么，很简单方便
    cout << cha;
    return 0;
}
