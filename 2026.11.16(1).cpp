//P8637任意数互换（环解法）
#include<iostream>
using namespace std;

int ans = 0;
int a[10005] = { 0 };
bool vis[10005] = { false };
int len_cycle = 0;

int main() {
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {                        //排好的情况下应当是数组下标对应其装的数字（例如a[1]应当为1）
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++) {            
		if (vis[i] == 0) {                                  //开始遍历。如果这个数字还没看过，环就从这里开始。
			len_cycle = 0;                                    
			int temp = i;                                     //看看a[i]里面的数字是什么，假如a[i]=i，下面的while循环只执行一次，环长度-1为0，不交换，不影响答案。
                                                        //假如a[i]=j，则需要交换，现在去找a[j]，再看看a[j]等于几，如果相等，多执行一次while循环再退出，环长度-1抵去这一次多余。
			while (vis[temp] == 0) {                          //若不等，则继续寻找下去。
				vis[temp] = 1;
				temp = a[temp];
				len_cycle++;
			}
			ans += (len_cycle - 1);
		}
	}
	cout << ans;
}
