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
        int n;
        cin >> n;
        vector<int> v(n), ans(n + 1);
        for(int i=0;i<n-1;i++) {
            cin >> v[i];
            ans[v[i]]++;
        }
        for(int i=1;i<=n;i++) {
            cout << ans[i] << endl;
        }
    }
}