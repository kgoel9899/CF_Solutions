#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
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
        vector<int> v(n);
        int s = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            s += v[i];
        }
        int ct = 0;
        sort(all(v), greater<int>());
        for(int i=0;i<m;i++) {
            if(v[i] * (4 * m) >= s) ct++;
        }
        if(ct == m) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}