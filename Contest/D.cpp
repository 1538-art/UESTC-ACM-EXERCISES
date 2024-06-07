#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N + 1), B(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= N; i++) {
    cin >> B[i];
  }
  
  vector<vector<vector<bool>>> dp(N + 1, vector<vector<bool>>(301, vector<bool>(301, false)));
  dp[0][0][0] = true;
  
  for (int i = 1; i <= N; i++) {
    vector<vector<vector<bool>>> temp = dp;
    for (int j = 0; j <= 300; j++) {
      for (int k = 0; k <= 300; k++) {
        if (j >= A[i] && dp[i - 1][j - A[i]][k]) {
          temp[i][j][k] = true;
        }
        if (k >= B[i] && dp[i - 1][j][k - B[i]]) {
          temp[i][j][k] = true;
        }
      }
    }
    dp = temp;
  }
  
  int res = 0;
  for (int j = 0; j <= 300; j++) {
    for (int k = 0; k <= 300; k++) {
      if (dp[N][j][k]) {
        res = max(res, min(j, k));
      }
    }
  }
  
  cout << res << endl;
  
  return 0;
}

// 13
// 12 11  9 13  8  7  6  5 14  4  3 10 15
//  6  7  9  5 10 11 12 13  4 14 15  8  3
//