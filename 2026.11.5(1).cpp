//P1518农夫抓牛
#include<iostream>
//#include<string>
using namespace std;
char MAP[12][12] = { 0 };
//string line[12] = { 0 };                            //这里是遗留了一个超级大炸弹，害我改了好久都没发现!!!!以后改代码一定一定改干净
int x_c = 0, y_c = 0, x_f = 0, y_f = 0;
int dir_C = 0, dir_F = 0;

int main() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'C') { x_c = i; y_c = j; }
			if (MAP[i][j] == 'F') { x_f = i; y_f = j; }
		}
	}
	for (int j = 0; j <= 11; j++) {				//将边界全变成障碍物
		MAP[0][j] = '*';
	}
	for (int j = 0; j <= 11; j++) {
		MAP[11][j] = '*';
	}
	for (int j = 0; j <= 11; j++) {
		MAP[j][0] = '*';
	}
	for (int j = 0; j <= 11; j++) {
		MAP[j][11] = '*';
	}
	//开始移动牛
	for (int i = 1; i <= 1000000; i++) {
		dir_C %= 4, dir_F %= 4;
		if (dir_C == 0) {
			if (MAP[x_c - 1][y_c] == '*') {
				dir_C++;
			}
			else {
				x_c--;
			}
		}
		else if (dir_C == 1) {
			if (MAP[x_c][y_c + 1] == '*') {
				dir_C++;
			}
			else {
				y_c++;
			}
		}
		else if (dir_C == 2) {
			if (MAP[x_c + 1][y_c] == '*') {
				dir_C++;
			}
			else {
				x_c++;
			}
		}
		else if (dir_C == 3) {
			if (MAP[x_c][y_c - 1] == '*') {
				dir_C++;
			}
			else {
				y_c--;
			}
		}
		//开始移动农夫
		if (dir_F == 0) {
			if (MAP[x_f - 1][y_f] == '*') {
				dir_F++;
			}
			else {
				x_f--;
			}
		}
		else if (dir_F == 1) {
			if (MAP[x_f][y_f + 1] == '*') {
				dir_F++;
			}
			else {
				y_f++;
			}
		}
		else if (dir_F == 2) {
			if (MAP[x_f + 1][y_f] == '*') {
				dir_F++;
			}
			else {
				x_f++;
			}
		}
		else if (dir_F == 3) {
			if (MAP[x_f][y_f - 1] == '*') {
				dir_F++;
			}
			else {
				y_f--;
			}
		}
	if ((x_c == x_f) && (y_c == y_f)) {
			cout << i;
			return 0;
		}
	}
	cout << "0";
	return 0;
}
