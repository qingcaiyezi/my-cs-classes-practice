//P1093奖学金-oop
//开始学习面向对象编程，同时学习STL的内容。此题学习class的运用。
#include<iostream>
#include<algorithm>
using namespace std;
class Students {
private:
	int chinese, math, english;                        //当然，此题没有必要单独给这些数字都放进private里面，因此完全可以用结构体。但是关乎今天学习的主题及往后工程习惯的实际需要，要以标准的方法写。
	int number;
	int total;
public:
	Students() {}                                      //为了开数组，需要默认的构造函数
	void input(int i, int c, int m, int e) {
		number = i;
		chinese = c;
		math = m;
		english = e;
		total = c + m + e;
	}
	int outputID() { return number; }
	int outputChinese() { return chinese; }
	int outputTotal() { return total; }
};

Students stu[305];

bool rule_of_com(Students a, Students b) {                                      //用于给sort函数自定义排序标准的函数。
	if (a.outputTotal() != b.outputTotal()) {
		return a.outputTotal() > b.outputTotal();
	}
	if (a.outputChinese() != b.outputChinese()) {
		return a.outputChinese() > b.outputChinese();
	}
	return a.outputID() < b.outputID();
}

int main() {
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		stu[i].input(i, a, b, c);
	}
	sort(stu + 1, stu + N + 1, rule_of_com);

	for (int i = 1; i <= 5; i++) {
		cout << stu[i].outputID() << " " << stu[i].outputTotal() << endl;
	}

}
