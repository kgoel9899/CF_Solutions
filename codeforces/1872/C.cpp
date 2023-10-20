// https://codeforces.com/contest/1872/submission/222227406
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int l, r;
    std::cin >> l >> r;
    
    for (int i = std::max(4, l); i <= r; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                std::cout << j << " " << i - j << "\n";
                return;
            }
        }
    }
    std::cout << -1 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
