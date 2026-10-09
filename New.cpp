#include<iostream>
using namespace std;
int main() {
    int n, i, max;
    double ans = 0;
    cin >> n;
    max = n * 10;
    for (i = 1; i <= max; i++) {
        ans += i;
    }
    ans *= 0.1;
    cout << ans;
    return 0;
}
