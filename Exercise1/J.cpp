/*
读入一个自然数n, 将n分解为质因子连乘的形式输出.

Standard Input
有多组测试数据. 输入的第一行是整数T（0<T<=10000）,
 表示测试数据的组数. 每一组测试数据只有一行, 由待分解的自然数n构成. 1<n<2^31.

Standard Output
对应每组输入, 输出一行分解结果, 具体样式参看样例.

Samples
  Input
5
756
2
2093333998
1846343116
559551846
  Output
756=2*2*3*3*3*7
2=2
2093333998=2*7*7*17*43*29221
1846343116=2*2*29*43*139*2663
559551846=2*3*7*41*53*6131
 */
#include <iostream>
#include <vector>

using namespace std;

// 函数用于将整数分解为质因子
void factorize(int n) {
  vector<int> primes;
  // 处理偶数
  while (n % 2 == 0) {
    primes.push_back(2);
    n /= 2;
  }
  // 遍历所有奇数，从3开始
  for (int i = 3; i * i <= n; i += 2) {
    // 当i是n的因子时
    while (n % i == 0) {
      primes.push_back(i);
      n /= i;
    }
  }
  // 如果n是一个质数
  if (n > 2) {
    primes.push_back(n);
  }
  // 输出分解结果
  for (size_t i = 0; i < primes.size(); ++i) {
    if (i > 0) cout << "*";
    cout << primes[i];
  }
  cout << endl;
}

int main() {
  int T; // 测试数据组数
  cin >> T;
  while (T--) {
    int n; // 待分解的自然数
    cin >> n;
    cout << n << "=";
    factorize(n);
  }
  return 0;
}