/**
 *    author:  tourist
 *    created: 19.12.2022 18:45:17       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector<int> suf(n);
    suf[n - 1] = a[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = min(suf[i + 1], a[i].second);
    }
    int dealt = 0;
    int ptr = 0;
    while (k > 0 && ptr < n) {
      dealt += k;
      while (ptr < n && a[ptr].first <= dealt) {
        ptr += 1;
      }
      if (ptr < n) {
        k -= suf[ptr];
      }
    }
    cout << (ptr == n ? "YES" : "NO") << '\n';
  }
  return 0;
}