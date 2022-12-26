#include <bits/stdc++.h>
using namespace std;

char c[1005];
int main() {
  int t;
  scanf("%d", &t);
  int n;
  while (t--) {
    scanf("%d", &n);
    scanf("%s", c + 1);
    int u = 0;
    for (int i = 1; i <= n; ++i) {
      bool fl = (c[i] == '1') && u;
      u ^= (c[i] - '0');
      if (i != 1) putchar(fl ? '-' : '+');
    }
    putchar('\n');
  }
}