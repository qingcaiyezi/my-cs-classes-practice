//P1223 排队接水（贪心算法）
//算法比较简单就不说了，重点要注意使用sort函数排序对象成员的写法
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
class People {
public:
	People() {};
	void get_time() {
		cin >> time;
	}
	void get_ID(int i) {
		ID = i;
	}
	int give_ID() {
		return ID;
	}
	int give_time() {
		return time;
	}
private:
	int time = 0;
	int ID = 0;
};
int n = 0;
bool cmp(People a, People b) {
	if (a.give_ID() != b.give_ID()) return a.give_time() < b.give_time();
	else return a.give_ID() < b.give_ID();
}
int main() {
	People* p = new People[1005];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		p[i].get_time();
		p[i].get_ID(i);
	}
	sort(p + 1, p + n + 1, cmp);
	long long total_time = 0;
	for (int i = 1; i <= n; i++) {
		total_time += p[i].give_time() * (n - i);
	}
	double ave = total_time * 1.0 / n;
	for (int i = 1; i < n; i++) {
		cout << p[i].give_ID() << " ";
	}
	cout << p[n].give_ID() << endl;
	cout << fixed << setprecision(2) << ave;
}
