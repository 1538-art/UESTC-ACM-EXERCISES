/*
很久很久以前，E国遭遇了一次巨大的冲击。E国的铁路运输网已经完全崩溃。
 但是伟大的列车托夫出现了，他领导着E国人重新开始修铁路。
 为了生产资料的运输，我们希望任意的两个城市都能够经由铁路直接或间接连通。

但是E国的城市修建的十分奇异，以至于每个城市至多只能和其它城市中的k座之间直接修建一条铁路。
 现在，E国有n个城市，那么？这里，认为在两个城市间直接铺设多条铁路是不合法的。
 如果无论怎么修建都不能连通所有城市，则输出0。

Standard Input
输入包含多组测试数据。第一行是一个整数T (T≤1000)，表示测试组数。
 随后有T行，每行有两个整数n,k(1≤n≤10000,0≤k≤10000)分别表示，
 E国城市的数目和每个城市最多能直接相连的城市个数。

Standard Output
对于每组输入数据，输出包含所求数目的一行。

Samples
Input
2
5 3
5 0
 	Output
7
0
 */
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (k == 0 || (n > 2 && k == 1)) cout << 0 << endl;
    else if (k > n - 2) cout << n * (n - 1) / 2 << endl;
    else cout << n * k / 2 << endl;
  }
  return 0;
}

