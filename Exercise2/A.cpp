/*
8球是一种台球竞赛的规则。台面上有
7个红球、
7个黄球以及一个黑球，当然还有一个白球。对于本题，我们使用如下的简化规则：
 红、黄两名选手轮流用白球击打各自颜色的球，如果将该颜色的
7个球全部打进，则这名选手可以打黑球，如果打进则算他胜。
 如果在打进自己颜色的所有球之前就把黑球打进，则算输。如果选手不慎打进了对手的球，入球依然有效。
现在给出打进的球（白球除外）的顺序，以及黑球由哪方打进，你的任务是判定哪方是胜者。
假设不会有一杆同时打进一颗黑球和其他彩球。

Standard Input
输入包含多组数据。每组数据第一行是一个整数
N(1≤N≤15)，表示打进的球的个数，
N=0表示结束。随后有一行，包含
N个字符，依序表示打进的是何种球。如果是
B，表示是红方打进的黑球，如果是
L，表示是黄方打进的黑球。如果是
Y则表示是黄球，
R表示红球。字符间没有空格。

所有输入都满足如下条件：最后一颗球打进时这局比赛正好结束，而且打进的红球和黑球都不超过
7
7个。

Standard Output
对每组数据，输出一行。如果红方胜，输出Red；黄方胜，输出Yellow。

Samples
  Input
5
RYRRB
9
RRRRYRRRB
0
 Output
Yellow
Red
 */
#include <iostream>

using namespace std;

int main() {
  int n;
  char x;
  while (true) {
    cin >> n;
    if (n == 0) break;
    int red = 0, yellow = 0;
    for (int i = 0; i < n - 1; ++i) {
      cin >> x;
      if (x == 'R') red++;
      else yellow++;
    }
    char f;
    cin >> f;
    if (f == 'B') {
      if (red == 7)cout << "Red" << endl;
      else cout << "Yellow" << endl;
    } else {
      if (yellow == 7)cout << "Yellow" << endl;
      else cout << "Red" << endl;
    }
  }
}