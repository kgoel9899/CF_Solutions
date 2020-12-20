#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        vector<int> l, r;
        for(int i=0;i<n;i++) {
            cin >> v[i].first >> v[i].second;
            l.push_back(v[i].first);
            r.push_back(v[i].second);
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        int ans = n - 1;
        for(auto i : v) {
            int a = lower_bound(r.begin(), r.end(), i.first) - r.begin();
            int b = n - (upper_bound(l.begin(), l.end(), i.second) - l.begin());
            b = max(0ll, b);
            ans = min(ans, a + b);
        }
        cout << ans << endl;
    }
}