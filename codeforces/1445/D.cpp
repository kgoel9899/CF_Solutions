#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int pp(int x, int y, int p) {
    int ans = 1;
    x %= p;
    while(y > 0) { 
        if((y & 1) == 1) ans = (ans * x) % p; 
        y >>= 1; 
        x = (x * x) % p; 
    } 
    return ans;
}
int modInv(int n) {
    return pp(n, mod - 2, mod);
}
int ncr_calc(int n, int r) {
    if(r == 0) return 1;
    vector<int> fact(n + 1);
    fact[0] = 1; 
    for(int i=1;i<=n;i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int ans = fact[n];
    ans %= mod;
    ans *= modInv(fact[r]);
    ans %= mod;
    ans *= modInv(fact[n - r]);
    ans %= mod;
    return ans;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(2 * n);
        for(int i=0;i<2*n;i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int left = 0, right = 0;
        for(int i=0;i<n;i++) {
            left += v[i];
            right += v[n + i];
        }
        int ans = ncr_calc(2 * n, n);
        ans = ans * ((right - left) % mod);
        ans %= mod;
        cout << ans << endl;
    }
}