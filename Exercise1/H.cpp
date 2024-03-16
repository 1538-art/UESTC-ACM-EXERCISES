/*
有数列定义为:F(0) = a, F(1) =b,F(n) = F(n-1)+F(n-2), 且0 < a < b < 20.现给出a, b, n,请问F(n)能否被3整除.

Standard Input
有多组测试数据.输入的第一行是整数T(1<=T<=20),表示随后测试数据的组数.
 每组测试数据的第一行是正整数a, b, m, a,b的含义如前所述,
 m表示随后有m行,每行为前面所述的n, 0 < m < 100, 0 < n < 10^9.

Standard Output
对应每组测试数据,共输出m行,如果每行对应的F(n)能被3整除,
 则输出一行”Yes”,否则输出一行”No”.两组测试数据的输出间,请输出一行空行.

Samples
  Input
2
10 14 9
0
1
2
4
5
325684
2569853
987654321
999999999
6 13 3
7
589
125328936
  Output
No
No
Yes
No
No
No
No
No
No
No
No
Yes
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> fibMod(8);
    fibMod[0] = a % 3;
    fibMod[1] = b % 3;
    for (int i = 2; i < 8; ++i) {
      fibMod[i] = (fibMod[i - 1] + fibMod[i - 2]) % 3;
    }
    while (m--) {
      int n;
      cin >> n;
      if (fibMod[n % 8] == 0) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
    if (T) {
      cout << endl;
    }
  }
  return 0;
}
