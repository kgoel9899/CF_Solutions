#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 1e6 + 5;
vector<int> vis(N), dp(N);
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        int s = 0;
        for(int i=1;i<=n;i++) {
            cin >> v[i];
            s += v[i];
        }
        if(s % n != 0) {
            cout << -1 << endl;
            continue;
        }
        vector<vector<int>> ans;
        for(int i=2;i<=n;i++) {
            if(v[i] % i == 0) {
                int div = v[i] / i;
                v[i] = 0;
                v[1] += div * i;
                ans.push_back({i, 1, div});
            } else {
                int div = v[i] / i;
                div++;
                int reqd = i * div - v[i];
                v[1] -= reqd;
                v[i] += reqd;
                ans.push_back({1, i, reqd});
                v[1] += div * i;
                v[i] = 0;
                ans.push_back({i, 1, div});
            }
        }
        int fin = s / n;
        for(int i=2;i<=n;i++) {
            ans.push_back({1, i, fin});
        }
        cout << ans.size() << endl;
        for(auto i : ans) {
            for(auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
}