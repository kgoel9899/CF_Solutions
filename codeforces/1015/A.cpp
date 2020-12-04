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
        vector<int> v(m + 1);
        for(int i=0;i<n;i++) {
            int l, r;
            cin >> l >> r;
            for(int j=l;j<=r;j++) {
                v[j] = 1;
            }
        }
        int ct = 0;
        for(int i=1;i<=m;i++) {
            if(v[i] == 0) ct++;
        }
        cout << ct << endl;
        for(int i=1;i<=m;i++) {
            if(v[i] == 0) cout << i << " ";
        }
        cout << endl;
    }
}