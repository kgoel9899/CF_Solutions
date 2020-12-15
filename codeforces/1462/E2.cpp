#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 2e5 + 5;
vector<int> fact(N);
void helper() {
    fact[0] = 1; 
    for(int i=1;i<N;i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
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
    return pp(n, MOD - 2, MOD);
}
int ncr_calc(int n, int r) {
    if(r == 0) return 1;
    int ans = fact[n];
    ans %= MOD;
    ans *= modInv(fact[r]);
    ans %= MOD;
    ans *= modInv(fact[n - r]);
    ans %= MOD;
    return ans;
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    helper();
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        // vector<int> ind(n);
        int ans = 0;
        for(int i=0;i<n;i++) {
            int ind = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
            // cout << v[i] << " " << ind << endl;
            ind--;
            int len = ind - i;
            if(len >= m - 1) {
                // len C m - 1
                // cout << "here" << endl;
                // cout << len << " " << m - 1 << endl;
                ans += ncr_calc(len, m - 1);
                ans %= MOD;
            }
        }
        cout << ans % MOD << endl;
    }
}