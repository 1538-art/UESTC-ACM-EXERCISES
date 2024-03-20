/*

 */
#include <iostream>

using namespace std;

int main() {
  int T, n, f, i, j;
  long sum = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &f);
    j = 2 * n - 1;
    sum = 0;
    for (i = 1; i <= n; i++) {
      sum += j * i;
      j -= 2;
    }
    if (sum > f) printf("-1\n");
    else {
      for (i = 1; i < n; i++) {
        printf("%d ", i);
      }
      printf("%ld\n", i + f - sum);
    }
  }
  return 0;
}
