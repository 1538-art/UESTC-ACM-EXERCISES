/*
P酱是个可爱的男孩子，有一天他在野外冒险，不知不觉中走入了一块神奇的地方。他在0时刻进入这个地方，
 每一时刻他都只能向某一特定的方向移动长度为1的距离，当然他也可以选择不移动。移动需要花费1的时间。
各个时刻他允许移动的方向由一个字符串给出，字符串只包含、D、L、R 四种字符，其中 表示向上（y轴正方向）移动， D表示向下（y轴负方向）移
动， L 表示向左（x轴负方向）移动， R 表示向右（x轴正方向）移动。
字符串的第r个字符代表了第r时刻P酱可以移动的方向，字符串的长度只有t，也就是说，超过时刻，P酱就要被邪恶的魔王大爷抓走了～
现在P酱在坐标原点，即(0,0)点，而出口在(c,y)点，P酱希望在规定的时间t内尽快走到出口。帮助P酱在最短的时间内离开这里吧~
Standard Input
第一行包含一个正数T (T≤ 100)，表示数据组数。
接下来每组数据包含两行，第一行包含三个整数 x,y,t (-10^5≤ x,y≤ 10^5,0 < t≤ 10^5); 第二行包含一个长度为t的字符串，第个字符表示在时刻他能移动的方向，字
符串只包含 ，，， 四种字母。
Standard Output
对于每组数据输出一行，表示P酱到达出口的最早时刻。如果他无法在时刻内到达出口，输出-1。
Samples
Input
2
1 -1 5
LDRDR
-2 1 8
RRUDDLRU
Output
 3
 -1
Note
第一组样例：
1.P酱在0时刻位于原点(0,0)，他只能向左移动，但他选择不走。
2. P酱在1时刻依然位于原点(0,0)，他只能向下移动，于是他向下移动到了(0,-1)
3.P酱在2时刻位于(0,－1)，他只能向右移动，于是他移动到了出口(1,－1)，所以在3时刻，P酱离开了这片区域!
 */
#include <bits/stdc++.h>

using namespace std;
#define N 100001

int direction(int x, int y) {
  if (x > 0 && y > 0)return 1;
  if (x > 0 && y < 0)return 3;
  if (x < 0 && y < 0)return 5;
  if (x < 0 && y > 0)return 7;
  if (x == 0 && y > 0)return 0;
  if (x > 0 && y == 0)return 2;
  if (x == 0 && y < 0)return 4;
  if (x < 0 && y == 0)return 6;
}

int main() {
  int T;
  char c[N] = {0};
  cin >> T;
  while (T--) {
    int x, y, t;
    int dir, i, a = 0, b = 0, time = -1;
    memset(c, 0, sizeof(char));
    cin >> x >> y >> t;
    getchar();
    scanf("%s", c);
    dir = direction(x, y);
    switch (dir) {
      case 0: {
        for (i = 0; i < t; i++) {
          if (b == y) {
            time = i;
            break;
          }
          if (c[i] == 'U' && b < y) b++;
        }
      }
        break;
      case 1: {
        for (i = 0; i < t; i++) {
          if (a == x && b == y) {
            time = i;
            break;
          }
          if (c[i] == 'R' && a < x) a++;
          else if (c[i] == 'U' && b < y) b++;
        }
      }
        break;
      case 2: {
        for (i = 0; i < t; i++) {
          if (a == x) {
            time = i;
            break;
          }
          if (c[i] == 'R' && a < x) a++;
        }
      }
        break;
      case 3: {
        for (i = 0; i < t; i++) {
          if (a == x && b == y) {
            time = i;
            break;
          }
          if (c[i] == 'R' && a < x) a++;
          else if (c[i] == 'D' && b > y) b--;
        }
      }
        break;
      case 4: {
        for (i = 0; i < t; i++) {
          if (b == y) {
            time = i;
            break;
          }
          if (c[i] == 'D' && b > y) b--;
        }
      }
        break;
      case 5: {
        for (i = 0; i < t; i++) {
          if (a == x && b == y) {
            time = i;
            break;
          }
          if (c[i] == 'L' && a > x) a--;
          else if (c[i] == 'D' && b > y) b--;
        }
      }
        break;
      case 6: {
        for (i = 0; i < t; i++) {
          if (a == x) {
            time = i;
            break;
          }
          if (c[i] == 'L' && a > x) a--;
        }
      }
        break;
      case 7: {
        for (i = 0; i < t; i++) {
          if (a == x && b == y) {
            time = i;
            break;
          }
          if (c[i] == 'L' && a > x) a--;
          else if (c[i] == 'U' && b < y) b++;
        }
      }
        break;
    }
    printf("%d\n", time);
  }
  return 0;
}

