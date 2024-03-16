/*
任给三个用一个空格隔开的整数，依次表示年、月、日，说出它是今年的第几天。定义该年的第1天是1月1日。

Standard Input
有多组测试数据.输入的第一行是整数T(1<=T<=200), 表示随后测试数据的组数. 每组测试数据占一行, 由三个分别表示年、月、日的正整数构成. 相邻两个数之间有一个空格.

Standard Output
对应每组测试数据, 输出一行的结果.

Samples
Input
7
2012 1 1
2012 3 1
2000 4 25
2000 9 1
2013 3 1
2013 8 31
2012 12 31
Output
1
61
116
245
60
243
366
 */

#include <iostream>

using namespace std;

int main() {
  int months[12] =
      {0, 31, 28, 31, 30, 31,
       30, 31, 31, 30, 31, 30};
  int T, y, m, d, day = 0;
  cin >> T;
  while (T-- > 0) {
    day = 0;
    cin >> y >> m >> d;
    // 如果年份是4的倍数且不是100的倍数，或者是400的倍数，则是闰年，2月有29天
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) months[2] = 29;
    else months[2] = 28;
    int i = 0;
    while (++i < m) {
      day += months[i];
    }
    cout << day + d << endl;
  }
}