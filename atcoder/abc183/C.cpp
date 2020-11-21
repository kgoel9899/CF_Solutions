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
    // cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> t(n + 1, vector<int>(n + 1));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cin >> t[i][j];
            }
        }
        vector<int> v;
        for(int i=1;i<=n;i++) {
            v.push_back(i);
        }
        int ans = 0;
        do {
            int cost = 0;
            for(int i=1;i<n;i++) {
                cost += t[v[i - 1]][v[i]];
            }
            cost += t[v[n - 1]][1];
            if(cost == k) ans++;
        } while(next_permutation(v.begin() + 1, v.end()));
        cout << ans << endl;
    }
}