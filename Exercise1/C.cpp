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
#include <vector>
#include <string>
using namespace std;
bool canResort(const string& a, const string& b) {
  vector<int> count(10, 0);
  for (char c : a) {
    count[c - '0']++;
  }
  for (char c : b) {
    count[c - '0']--;
  }
  for (int i : count) {
    if (i != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    string a, b;
    cin >> a >> b;

    if (canResort(a, b)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}