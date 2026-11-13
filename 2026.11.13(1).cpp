//P1002过河卒（DP）
#include<iostream>
using namespace std;

long long ways[50][50] = { 0 };
int stop[50][50] = { 0 };
int n, m, mx, my;

void mark(int row, int col) {
    if (row >= 0 && row <= m && col >= 0 && col <= n) {
        stop[row][col] = 1;
    }
}

int main() {
    cin >> n >> m;
    cin >> mx >> my;

    mark(my, mx);

    mark(my - 2, mx - 1);
    mark(my - 2, mx + 1);
    mark(my - 1, mx - 2);
    mark(my - 1, mx + 2);
    mark(my + 1, mx - 2);
    mark(my + 1, mx + 2);
    mark(my + 2, mx - 1);
    mark(my + 2, mx + 1);

    if (!stop[0][0]) {
        ways[0][0] = 1;
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) continue;
            
            if (stop[i][j]) {
                ways[i][j] = 0;
                continue;
            }

            if (i > 0) ways[i][j] += ways[i - 1][j];
            if (j > 0) ways[i][j] += ways[i][j - 1];
        }
    }

    cout << ways[m][n];
    return 0;
}
