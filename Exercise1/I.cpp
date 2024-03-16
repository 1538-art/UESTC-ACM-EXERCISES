/*
读入一个全由小写英文构成的字符串, 求出其中最长的回文子串.
 回文串是指正着看和倒着看相同, 如abba和yyxyy.
Standard Input
有多组测试数据。第一行是整数T (T <= 100)，表示测试数据的组数，
 随后有T组测试数据。每一组测试数据占一行，是一个长度不超过1000的全由小写英文构成的字符串.
Standard Output
对应每组输入，输出最长回文子串. 如果有多个最长子串, 则输出下标最小的那个.
Samples
  Input
5
abcddca
aabcdeef
abcdcba
abcd
abcdcaeee
 Output
cddc
aa
abcdcba
a
cdc
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 1, start = 0;
    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;                      // 单个字符是回文串
      if (i < n - 1 && s[i] == s[i + 1]) {
        dp[i][i + 1] = true;                // 两个相同字符是回文串
        if (maxLen == 2)continue;           // 如果已经有长度为2的回文串，就不用再更新了
        maxLen = 2;
        start = i;
      }
    }
    
    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i + len - 1 < n; ++i) {
        int j = i + len - 1;
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          if (len > maxLen) {               // 如果找到了更长的回文串，就更新maxLen和start
            maxLen = len;
            start = i;
          }
        }
      }
    }
    cout << s.substr(start, maxLen) << endl;
  }
  return 0;
}