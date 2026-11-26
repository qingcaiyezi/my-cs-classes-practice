//P1803 线段覆盖
//这个的想法值得注意一下，此处需要：结束时间足够早，开始时间足够晚或终点足够前与起点足够后
#include<iostream>
#include<algorithm>	

using namespace std;

class Comp {
public:
	Comp() {};
	void get_start() {
		cin >> start;
	}
	void get_end() {
		cin >> end;
	}
	void time_cal() {
		length = end - start;
	}
	int give_start() {
		return start;
	}
	int give_end() {
		return end;
	}
	int give_length() {
		return length;
	}
private:
	int start = 0;
	int end = 0;
	int length = 0;
};

int ans = 0;
int n = 0;

bool cmp(Comp a, Comp b) {
	if (a.give_end() != b.give_end()) return a.give_end() < b.give_end();
	else if (a.give_start() != b.give_start()) return a.give_start() > b.give_start();
}

int main() {
	cin >> n;
	Comp* p = new Comp[n + 1];
	for (int i = 1; i <= n; i++) {
		p[i].get_start();
		p[i].get_end();
		p[i].time_cal();
	}
	sort(p + 1, p + n + 1, cmp);
	int time_now = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i].give_start() >= time_now) {
			time_now = p[i].give_end();
			ans++;
		}
	}
	cout << ans;
}
