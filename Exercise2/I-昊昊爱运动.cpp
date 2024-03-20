/*
昊昊喜欢运动
他N天内会参加M种运动(每种运动用一个[1,m]的整数表示)
舍友有Q个问题
问昊昊第l天到第r天参加了多少种不同的运动

Standard Input
输入两个数N, M (1 ≤ N ≤ 2000,1 ≤ M ≤ 100);
输入N个数ai表示在第i天昊昊做了第a类型的运动;
输入—个数Q(1 ≤Q ≤ 106);
输入Q行每行两个数l,r(1 ≤ l ≤r ≤n);

Standard Output
一共Q行
每一行输出一个数表示昊昊在第天到第r天一共做了多少种活动

Samples
Input
5 3
1 2 3 2 2
3
1 4
2 4
1 5
Output
 3
 2
 3
 Input
 7 5
 1 2 3 1 2 5 4
 7
 1 3
 2 4
 1 4
 5 7
 1 5
 1 6
 1 7
 Output
 3
 3
 3
 3
 3
 4
 5
 */
/* 版本三 莫队算法 */
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 2005;
const int MAXQ = 1e6+5;
const int MAXM = 105;

struct Query {
    int l, r, id;
} q[MAXQ];

int n, m, Q, a[MAXN], ans[MAXQ], cnt[MAXM], res;

bool cmp(const Query &x, const Query &y) {
  int bx = x.l / sqrt(n), by = y.l / sqrt(n);
  if(bx != by) return bx < by;
  return bx & 1 ? x.r < y.r : x.r > y.r;
}

void add(int x) {
  if(++cnt[a[x]] == 1) ++res;
}

void del(int x) {
  if(--cnt[a[x]] == 0) --res;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%d", &Q);
  for(int i = 1; i <= Q; ++i) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].id = i;
  }
  sort(q + 1, q + Q + 1, cmp);
  for(int i = 1, l = 1, r = 0; i <= Q; ++i) {
    while(l < q[i].l) del(l++);
    while(l > q[i].l) add(--l);
    while(r < q[i].r) add(++r);
    while(r > q[i].r) del(r--);
    ans[q[i].id] = res;
  }
  for(int i = 1; i <= Q; ++i) printf("%d\n", ans[i]);
  return 0;
}

/*版本二，超时
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  vector<vector<int>> countTypes(N + 1, vector<int>(N + 1, 0));
  vector<int> count(M + 1, 0);
  for (int i = 1; i <= N; i++) {
    int num = 0;
    for (int j = i; j <= N; j++) {
      if (count[a[j]] == 0) {
        count[a[j]]++;
        num++;
      }
      countTypes[i][j] = num;
    }
    // 重置count
    for (int j = 0; j <= M; j++) {
      count[j] = 0;
    }
  }
  int Q;
  cin >> Q;
  while (Q-- > 0) {
    int l, r;
    cin >> l >> r;
    cout << countTypes[l][r] << endl;
  }
}
 */
/* 版本一，超时
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  int Q;
  cin >> Q;
  
  while (Q-- > 0) {
    int l, r;
    cin >> l >> r;
    cout << countTypes(a, M, l, r) << endl;
  }
}
int countTypes(vector<int> a, int M, int l, int r) {
  vector<int> b(M + 1, 0);
  for (int i = l; i <= r; i++) {
    b[a[i]]++;
  }
  int count = 0;
  for (int i = 1; i <= M; i++) {
    if (b[i] > 0)
      count++;
  }
  return count;
}
*/