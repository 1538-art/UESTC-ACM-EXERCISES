/*
运动员跳水时，有n个评委打分，分数为10分制，且有两位小数。得分规则为：去掉最高分和最低分，求剩下分数的平均值，就是运动员的最终得分。

Standard Input
有多组测试数据。第一行是整数T (T <= 100)，表示测试数据的组数，随后有T组测试数据。每一组测试数据占一行，分别为整数n和n个评委的打分，相邻数之间有一个空格。其中，2<n≤100。

Standard Output
对应每组输入，输出该运动员的得分，保留2位小数。

Samples
Input
3
9 6.21 9.19 6.34 9.22 6.85 8.50 6.85 6.95 6.03
8 6.75 6.23 9.86 9.37 6.90 7.88 9.13 6.15
9 9.11 7.68 8.93 7.53 8.92 9.52 7.78 8.70 6.69
 Output
7.27
7.71
8.38
 */
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int T, n;
  cin >> T;
  while (T-- > 0) {
    cin >> n;
    auto *scores = (float *) malloc(sizeof(float) * n);
    for (int i = 0; i < n; i++) {
      cin >> scores[i];
    }
    sort(scores, scores + n);
    float sum = 0;
    for (int i = 1; i < n - 1; i++) {
      sum += scores[i];
    }
    float N = (float) n - 2;
    cout << fixed << setprecision(2) << sum / N << endl;
  }
}