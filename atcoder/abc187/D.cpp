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
        int n;
        cin >> n;
        vector<int> v(n);
        int fi = 0, se = 0;
        for(int i=0;i<n;i++) {
            int a, b;
            cin >> a >> b;
            v[i] = 2 * a + b;
            fi += a;
        }
        sort(all(v));
        int ans = 0;
        while(fi >= se) {
            se += v.back();
            v.pop_back();
            ans++;
        }
        cout << ans << endl;
    }
}