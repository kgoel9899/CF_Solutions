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
        int n, m;
        cin >> n >> m;
        vector<int> v(m);
        int sum = 0;
        for(int i=0;i<m;i++) {
            cin >> v[i];
            sum += v[i];
        }
        if(n - sum < 0) cout << -1 << endl;
        else cout << n - sum << endl;
    }
}