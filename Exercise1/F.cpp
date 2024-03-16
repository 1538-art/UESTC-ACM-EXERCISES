/*
在m只猴子聚在一起选大王, 商定规则如下:
 大家围成一圈, 按顺时针从1编号, 第一次从编号为1的开始报数, 以后循环进行,
 当报到n时退出圈子, 下一只则重新从1开始报数, 圈子中剩下的最后一只猴子则为大王.

Standard Input
有多组测试数据. 输入的第一行是整数T(1<=T<=100),
 表示随后测试数据的组数. 每组测试数据占一行,
 由正整数m和n组成, 两数之间有一个空格. 1 <= m,n <= 200.

Standard Output
对应每组测试数据, 输出选出的大王的猴子编号.

Samples
Input
4
3 2
1 23
20 1
20 3

 Output
3
1
20
20
 */
#include <iostream>

using namespace std;

// 递归求解约瑟夫环问题
int josephus(int n, int m) {
    if (n == 1)
        return 0;
    else
        return (josephus(n - 1, m) + m) % n;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        cout << josephus(m, n) + 1 << endl;
    }
    return 0;
}