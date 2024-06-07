/*
There are N people passing the ball. It starts from the first person,
 and each time the person who gets the ball should pass the ball to another one.
 So what is the number of situations in which
 the ball is passed back to the first person after passing M times.

Standard Input
Including two integers N and M, and N∈[2,9],M∈[1,15].

Standard Output
The answer，and it does not exceed 2^31.

Samples
Input
3 2
Output
2
 */
#include <iostream>
#include <vector>

using namespace std;

int count_situations(int N, int M, int current, vector<vector<int>>& memo) {
    if (M == 0) {
        if (current == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if (memo[M][current] != -1) {
        return memo[M][current];
    }

    int total = 0;
    for (int i = 0; i < N; i++) {
        if (i != current) {
            total += count_situations(N, M - 1, i, memo);
        }
    }
    memo[M][current] = total;
    return total;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> memo(M + 1, vector<int>(N, -1));
    cout << count_situations(N, M, 0, memo) << endl;
    return 0;
}

/*
#include <vector>
#include <iostream>

using namespace std;

int count_situations(int N, int M) {
  vector<vector<int>> dp(M, vector<int>(N + 1, 0));
  for (int i = 2; i <= N; i++) dp[1][i] = 1;
  for (int i = 2; i < M; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        if (j != k) {
          dp[i][j] += dp[i - 1][k];
        }
      }
    }
  }
  int sum = 0;
  for (int i = 2; i <= N; i++) sum += dp[M - 1][i];
  return sum;
}

int main() {
  int N, M;
  cin >> N >> M;
  cout << count_situations(N, M) << endl;
  return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, M, x;
  cin >> N >> M;
  x = (int) pow(N - 1, M) + (int) pow(-1, M) * (N - 1);
  printf("%d", x / N);
  return 0;
}
*/

