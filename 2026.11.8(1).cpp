//P1923求第K小的数（禁用nth_element，时间限制1s）
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 5000005;
int n = 0;
int a[MAX] = { 0 };
int k = 0;

void qc (int l, int r, int k) {                      //在本题中手写分治思想的快速选择算法是正解，时间复杂度是O(n)
    if (l >= r) return;                              //递归的终止条件，当待排的区间左右端点重合或错位时代表排序结束，应退出
    int mid = a[(l + r) / 2];                        //取基准值，例如正中间位置的数值
    int i = l;                                       //将左边界与右边界存入左右移动的指针
    int j = r;  
    while (i <= j) {
        while (a[i] < mid) i++;                      //发现左/右边比基准值大/小的值，指针停止
        while (a[j] > mid) j--;
        if (i <= j) {
            swap(a[i], a[j]);                        //将这两个错位的值互换，使其符合左右对基准值的大小
            i++;
            j--;
        }
    }
    if (k <= j) qc(l, j, k);                         //递归，要找的位置是k，看k在哪边，然后在这个区间递归，剩下那个区间不必理会
    else if (k >= i) qc(i, r, k);
}

int main() {
    ios::sync_with_stdio(false);                      //快读的一种方法，防超时
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    //需要注意的是，该算法并没有对数组进行真正的排序，故在需要完整排序的时候还应该使用快排或sort。
    qc(0, n - 1, k);
    cout << a[k];
}
