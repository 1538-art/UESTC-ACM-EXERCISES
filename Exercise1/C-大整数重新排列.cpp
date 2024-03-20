/*
读入两个非负大整数，判断其中一个是否能由另一个大整数内的数字重新排列得到。

Standard Input
有多组测试数据。输入的第一行是整数T(1<=T<=200)，
 表示随后有T组测试数据。每组测试数据占两行，每行是一个非负大整数, 位数不超过100.

Standard Output
对应每组测试数据，若其中一个大整数可以由另一个大整数重新排列得到,
 输出”Yes”, 否则输出”No”.

Samples
Input
4
12345678
85673421
12131416
63421111
46783
60708304
56793200
68579320
 Output
Yes
Yes
Yes
No
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(char a, char b) {
  return a > b;
}

int main() {
  int T, a_size, b_size, i;
  cin >> T;
  while (T--) {
    char a[101] = {0}, b[101] = {0};
    cin >> a >> b;
    a_size = static_cast<int>(strlen(a));
    b_size = static_cast<int>(strlen(b));
    sort(a, a + a_size, cmp);
    sort(b, b + b_size, cmp);
    if (a_size < b_size) {
      for (i = 0; i < b_size - a_size; i++)
        a[a_size + i] = '0';
    } else if (a_size > b_size) {
      for (i = 0; i < a_size - b_size; i++)
        b[b_size + i] = '0';
    }
    if (strcmp(a, b) != 0)
      cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  return 0;
}