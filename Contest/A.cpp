#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  vector<map<int, int>> count(t + 1);
  vector<int> min_count(t + 1, INT_MAX), max_count(t + 1, 0);
  vector<int> tested_minutes(t + 1, 0);
  while (n--) {
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      if (count[x].count(i) == 0) {
        tested_minutes[x]++;
      }
      count[x][i]++;
      min_count[x] = min(min_count[x], count[x][i]);
      max_count[x] = max(max_count[x], count[x][i]);
    }
  }
  for (int i = 1; i <= t; i++) {
    if (tested_minutes[i] < m) min_count[i] = 0;
    cout << min_count[i] << " " << max_count[i] << endl;
  }
  return 0;
}



/*
3 2 3
1 2
2 3
2 3

3 4 3
2 3 2 2
2 3 3 2
2 2 3 2
*/