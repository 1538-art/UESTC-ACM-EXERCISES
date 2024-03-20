/*
小明发现了一种特殊的N×M的矩阵，矩阵里的元素都是1或−1。
 假设为第i 行(1≤i≤N) 所有元素的乘积，为第j 列(1≤j≤M) 所有元素的乘积。
 喜欢搞事情的小明突发奇想，想知道有多少个不相同的，大小为N×M的矩阵使得所有都是K的(K=1 或者 −1)。
当且仅当两个矩阵存在一个元素不相同时两个矩阵不相同。

Standard Input
输入只有一行，三个数字N,M,K。(1≤N≤6,1≤M≤7,K=1或者−1)

Standard Output
输出一个数字，即满足条件的不同矩阵的数量

Samples
Input	Output
2 2 1   2
Note
这两个不同的矩阵分别是
1 1
1 1
和
-1 -1
-1 -1
 */
#include <iostream>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == -1 && (n + m) % 2) cout << 0;
  else printf("%d", 1 << (n - 1) * (m - 1));
  return 0;
}
