#include <bits/stdc++.h>
using namespace std;

int digit_sum(int n) {
    int ret = 0;
    while(n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    set<int> s;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] > 9) s.insert(i);
    }
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int l, r; cin >> l >> r; --l, --r;
            int lst = l;
            while(!s.empty()) {
                auto it = s.lower_bound(lst);
                if(it == s.end() || *it > r) break;
                a[*it] = digit_sum(a[*it]);
                int paiu = *it;
                s.erase(it);
                if(a[paiu] > 9) s.insert(paiu);
                lst = paiu + 1;
            }
        } else {
            int x; cin >> x; --x;
            cout << a[x] << "\n";
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	int t; cin >> t;
	while(t--) {
	    solve();
	}
}