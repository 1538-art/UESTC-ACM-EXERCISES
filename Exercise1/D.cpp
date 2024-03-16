/*
有n盏灯, 编号为1~n. 第1个人把所有灯打开, 第2个人按下所有编号为2的倍数的开关(这些灯将被关掉), 第3个人按下所有编号为3的倍数的开关(其中关掉的灯将被打开, 开着的灯将被关闭), 依此类推. 一共有k个人, 问最后有哪些灯开着?

Standard Input
有多组测试数据. 输入的第一行是整数T(0<T≤100), 表示测试数据的组数. 每一组测试数据只有一行, 依次为正整数n和k, 两数之间有一个空格. k<=n<=1000.

Standard Output
对应每组输入, 输出一行还开着灯的编号, 按从小到大的顺序, 每个编号后有一个空格.

Samples
Input
3
7 3
15 10
20 7
 Output
1 5 6 7
1 4 9 11 12 13 14 15
1 4 8 10 11 12 13 14 15 16 17 19
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, k;
        cin >> n >> k;
        vector<bool> lights(n + 1, false);
        for (int i = 1; i <= k; ++i) {
            for (int j = i; j <= n; j += i) {
                lights[j] = !lights[j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (lights[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}