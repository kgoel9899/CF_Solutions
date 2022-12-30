#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int fl = 0;
    for (int i = 1; i <= m; ++i) {
      int a;
      scanf("%d", &a);
      if (a == (n + k - 1) / k) ++fl;
      if (a > (n + k - 1) / k) fl = 1 << 30;
    }
    puts(fl <= (n - 1) % k + 1 ? "YES" : "NO");
  }
}