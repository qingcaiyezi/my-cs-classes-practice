//P4924魔法少女scarlet（矩阵旋转）
#include<iostream>
#include<string>
using namespace std;
int jvzhen[500][500] = { 0 }, temp[500][500] = { 0 };
string order[500];
int x , y, r, dir;
void rotate(int x, int y, int r, int dir) {
	int Lx = x - r;				//左上角
	int Ly = y - r;
	int Rx = x + r;				//右下角
	int Ry = y + r;
	for (int i = Lx; i <= Rx; i++) {
		for (int j = Ly; j <= Ry; j++) {
			if (dir == 0) {															//用四个角旋转推出的旋转通式
				temp[Lx + (j - Ly)][Ry - (i - Lx)] = jvzhen[i][j];
			}
			else {
				temp[Lx + (Ry - j)][Ly + (i - Lx)] = jvzhen[i][j];
			}
		}
	}
	for (int i = Lx; i <= Rx; i++) {									//将有变化的部分抄送回jvzhen数组
		for (int j = Ly; j <= Ry; j++) {
			jvzhen[i][j] = temp[i][j];
			temp[i][j] = 0;                               //清零保险防止污染
		}
	}
}

int main() {
	int n = 0, m = 0;
	int filling = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			jvzhen[i][j] = filling++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> r >> dir;
		rotate(x, y, r, dir);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < n) {
				cout << jvzhen[i][j] << " ";
			}
			else {
				cout << jvzhen[i][j] << endl;
			}
		}
	}
}
