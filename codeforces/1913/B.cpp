// https://codeforces.com/contest/1913/submission/237734023
// CHECK
/**
 *    author:  tourist
 *    created: 18.12.2023 09:37:30       
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
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> cnt(2);
    for (char c : s) {
      cnt[(int) (c - '0')] += 1;
    }
    vector<int> need(2);
    int ans = n;
    for (int i = 0; i < n; i++) {
      need[(int) (s[i] - '0') ^ 1] += 1;
      if (cnt[0] >= need[0] && cnt[1] >= need[1]) {
        ans = n - 1 - i;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}