#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
vector<int> G[maxn];
ll sz[maxn], n, ans;

void dfs(int u, int fa) {
  sz[u] = 1;
  for (auto v: G[u]) {
    if (v == fa) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
  ans += sz[u] * (n - sz[u]);
}

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    G[i].push_back(p);
    G[p].push_back(i);
  }
  dfs(1, 0);
  ll tot = n * (n - 1) / 2;
  ll g = gcd(ans, tot);
  cout << ans / g << "/" << tot / g << "\n";
  return 0;
}
