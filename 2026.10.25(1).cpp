//P5461
#include<iostream>
using namespace std;
int n = 0;
int a[1025][1025] = {0};
void chuli(int x, int y, int n) {                    //运用递归函数，将矩阵一直分到不能再分，因此不能分时将余下的元素由0改1
    if (n == 0) {
        a[x][y] = 1;
    }    else {
        chuli (x, y + (1 << (n-1)), n - 1);        //左下角矩阵
        chuli (x + (1 << (n-1)), y + (1 << (n-1)), n-1);      //右下角矩阵
        chuli (x + (1 << (n-1)), y, n-1);        //右上角矩阵            //C++中习惯是先上下再左右，与数学x,y定义不太一样，要注意，因此这三个注释打的不对，但由于
    }                                                                   //是标准的方阵，所以不影响答案，但一定要改习惯，尽量使用col和row
}



int main() {
    cin >> n;
    chuli (0, 0, n);
    for (int i = 0; i < (1 << (n)); i++) {        //行循环
        for (int j = 0; j < (1 << (n)); j++) {    //列循环
            cout << a[i][j];
            if (j == (1 << (n))-1) {                                      //采用左移，速度比pow(n,2)快，且不用引用头文件
                cout << endl;
            }    else {
                cout << " ";
            }
        }
    }
}
