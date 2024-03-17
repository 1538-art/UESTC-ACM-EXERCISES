/*
在一根细木杆上，有一些速度相同蚂蚁，它们有的往左走，有的往右走，木杆很细，只允许一只蚂蚁通过，
 所以当两只蚂蚁碰头的时候，它们会掉头继续前进，直到走出边界，掉下木杆。

已知木杆的长度和每只蚂蚁的名字、位置和初始方向，问依次掉下木杆的蚂蚁花费的时间以及它的名字。

Standard Input
输入包含多组测试数据。

第一行包含一个整数T(T≤20)，代表测试数据组数。

每组测试数据的第一行包含两个整数N, L，表示有N只蚂蚁(N≤100)，木杆长度为L(L≤1000)。
 假设蚂蚁每秒前进一个单位距离，掉头转向的时间忽略不计。

以下N行，每行依次为蚂蚁的名字（长度不超过10，仅由英文字母组成），初始位置p（0<p<L，整数，表示蚂蚁离木杆最左端的距离），
 初始方向（一个字符，L表示向左，R表示向右），以单个空格分隔，数据保证初始不会有两只蚂蚁在同一个位置。

Standard Output
对于第k组测试数据，首先输出一行为Case #k:。

然后输出N行，给出依次掉下木杆的蚂蚁花费的时间以及它的名字，以单个空格分隔。
（按照掉下木杆的先后顺序输出，数据保证不会有两支蚂蚁同时掉下木杆）。

Samples
  Input
2
2 5
GG 1 L
MM 3 R
2 5
GG 1 R
MM 2 L
 	Output
Case #1:
1 GG
2 MM
Case #2:
2 GG
4 MM
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ant {
    string name;
    int position;
    char direction;
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N, L;
    cin >> N >> L;
    vector<Ant> ants(N);
    vector<int> times(N);
    for (int i = 0; i < N; ++i) {
      cin >> ants[i].name >> ants[i].position >> ants[i].direction;
      times[i] = ants[i].direction == 'L' ? ants[i].position : L - ants[i].position;
    }
    
    sort(times.begin(), times.end());
    
    cout << "Case #" << t << ":" << endl;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (times[i] == (ants[j].direction == 'L' ? ants[j].position : L - ants[j].position)) {
          cout << times[i] << " " << ants[j].name << endl;
          ants[j].position = -1;  // Mark this ant as "fallen"
          break;
        }
      }
    }
  }
  
  return 0;
}
