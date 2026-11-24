//P1036
//写递归函数可以理解为写了个未定次数的循环，即：“递归 = 层数由运行期数据决定的循环”
#include<iostream>
using namespace std;

int num[25] = { 0 };
int k = 0, n = 0;
int ans = 0;


bool is_Prime(int x) {                                  //判断质数
	if (x < 2) return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

void proc(int start, int times, int sum) {              //传入：找数起点，当前次数，当前和
	if (times == k) {                                     //进来发现次数满了：判断是否质数，是则答案加一，“归回来”
		if (is_Prime(sum)) ans++;
		return;
	}
	for (int i = start; i <= n; i++) {                    //从找数起点开始遍历数组
		if (n - i + 1 < k - times) break;                   //如果剩下的数的个数不够了，直接break不浪费时间
		proc(i + 1, times + 1, sum + num[i]);               //从当前（i）的下一个数开始，延续一样的逻辑开始找，“递出去”；start指的是在start以后的数都遍历一次作为起点，即最小的起点
	}
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	proc(1, 0, 0);                                        //起点调用，找数起点是num[1]，次数和加和都是0
	cout << ans;
}
