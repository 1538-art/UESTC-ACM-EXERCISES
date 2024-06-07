#include <iostream>
#include <vector>

using namespace std;

const int maxn = 10;
double a[maxn], l, r;
int n, vis[maxn];
vector<pair<int, pair<int, int>>> ans;

void dfs(int id, double val) {
  if (ans.size() == n - 1) {
    if (val >= l && val <= r) {
      for (auto &p : ans) {
        cout << p.first + 1 << " " << p.second.first << " " << p.second.second + 1 << endl;
      }
      exit(0);
    }
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      vis[i] = 1;
      ans.push_back({id, {0, i}});
      a[id] = val + a[i];
      dfs(id, val + a[i]); // 串联操作
      ans.pop_back();
      ans.push_back({id, {1, i}});
      a[id] = 1 / (1 / val + 1 / a[i]);
      dfs(id, 1 / (1 / val + 1 / a[i])); // 并联操作
      ans.pop_back();
      vis[i] = 0;
    }
  }
}

int main() {
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    vis[i] = 1;
    dfs(i, a[i]);
    vis[i] = 0;
  }
  return 0;
}


/*
6
23 24
3 4 5 6 7 8

1 0 2
3 0 5
1 1 4
3 0 6
1 0 3

 */