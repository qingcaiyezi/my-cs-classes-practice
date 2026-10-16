//P2550彩票摇奖
#include<iostream>
using namespace std;
int main() {
    int n = 0, zhongjiang[10], xiaoming[10];
    int ansT = 0, ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0, ans6 = 0, geshu = 0;      
    cin >> n;                                         
    for (int i = 1; i <= 7; i++) {                    //循环次数写错成8了，导致所有数WA，以后要注意
        cin >> zhongjiang[i];
    }
    for (int j = 1; j <= n; j++) {
        geshu = 0;                                    //一定要注意，下面循环结束后，前一次彩票的ans就没用了，到这里一定要清零0！！！！
        for (int k = 1; k <= 7; k++) {                //即循环结束后，单次用的计数器一定要清零
            cin >> xiaoming[k];
        }
        for (int l = 1; l <= 7; l++) {
            for(int m = 1; m <= 7; m++) {
                if (zhongjiang[m] == xiaoming[l]) {
                    geshu++;
                }
            }
        }
        switch (geshu) {                                //关于记录彩票中奖次数的记录，可以使用标记数组的方法。
            case 7 : ansT++; break;
            case 6 : ans1++; break;
            case 5 : ans2++; break;
            case 4 : ans3++; break;
            case 3 : ans4++; break;
            case 2 : ans5++; break;
            case 1 : ans6++; break;
        }
    }
    cout << ansT << " " << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << " " << ans5 << " " << ans6;        
    return 0;
}
