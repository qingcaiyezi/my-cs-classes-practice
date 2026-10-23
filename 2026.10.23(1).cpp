//P5738
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int n, m;
int scores[25] = {0};
int maxsum = 0;
void chuli(int scores[], int m) {
    int sum = 0;
    int maxscore = 0;
    int minscore = 10;
    for (int i = 1; i <= m; i++) {
        maxscore = max(scores[i], maxscore);
        minscore = min(scores[i], minscore);
        sum += scores[i];
    }
    sum = sum - maxscore - minscore;
    maxsum = max(sum, maxsum);
}
int main() {
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> scores[j];
        }
        chuli(scores, m);
    }
    cout << fixed << setprecision(2) << (double)maxsum / (m - 2);
}
