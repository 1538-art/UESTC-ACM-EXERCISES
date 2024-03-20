
#include <bits/stdc++.h>

using namespace std;

int verdict(string s) {
  int pos, len;
  len = s.size();
  pos = s.rfind(" no good", len - 1);
  if (pos == len - 8) return pos;
  else return -1;
}


int main() {
  while (1) {
    int i, n;
    int flag = 0, status = 0;
    string l, a, b, s;
    char score1 = '0', score2 = '0', turn = '1';
    scanf("%d", &n);
    getchar();
    i = n;
    if (n == 0) break;
    while (n--) {
      getline(cin, s);
      status = verdict(s);
      switch (status) {
        case -1: {
          if (flag) {
            b.append("O ");
            score2++;
            flag = !flag;
          } else {
            a.append("O ");
            score1++;
            l.push_back(turn++);
            l.push_back(' ');
            flag = !flag;
          }
        }
          break;
        default: {
          if (flag) {
            b.append("X ");
            flag = !flag;
          } else {
            a.append("X ");
            l.push_back(turn++);
            l.push_back(' ');
            flag = !flag;
          }
        }
          break;
      }
    }
    if (i % 2) b.append("- ");
    l.append("Score");
    a.push_back(score1);
    b.push_back(score2);
    cout << l << endl;
    cout << a << endl;
    cout << b << endl;
  }
  return 0;
}

