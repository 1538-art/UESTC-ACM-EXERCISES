
#include<iostream>

using namespace std;

int main() {
  int n, ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans_1, ans_2, ans;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if ((i + 1) % 2 == 0) {
      if (s[i] != '0') ans2++;
    } else {
      if (s[i] != '1') ans1++;
    }
  }
  ans_1 = max(ans1, ans2);
  
  for (int i = 0; i < n; i++) {
    if ((i + 1) % 2 == 0) {
      if (s[i] != '1') ans3++;
    } else {
      if (s[i] != '0') ans4++;
    }
  }
  ans_2 = max(ans3, ans4);
  
  cout << min(ans_1, ans_2);
  return 0;
}
