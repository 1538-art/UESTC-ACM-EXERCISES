/*
读入一个n*n的字符矩阵, 绕矩阵中心顺时针旋转90度并输出结果.

Standard Input
有多组测试数据。第一行是整数T (T <= 100)，表示测试数据的组数，随后有T组测试数据。每一组测试数据的第一行是正号数n, 随后是一个n*n的全由小写英文字符构成的字符矩阵, n < 100.

Standard Output
对应每组输入，输出绕矩阵中心顺时针旋转的字符矩阵, 每组给出完成后, 再输出一个空行.
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    int n;
    cin >> n;
    vector<vector<char>> matrix(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> matrix[i][j];
      }
    }
    vector<vector<char>> rotated(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        rotated[j][n - i - 1] = matrix[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << rotated[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}