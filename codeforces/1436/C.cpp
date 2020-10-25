#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define vi vector<int>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define pb push_back
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int solve(int n) {
    int fact = 1;
    while(n > 0) {
        fact *= n;
        n--;
        fact %= MOD;
    }
    return fact;
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
    vi fact(n + 1);
    fact[0] = 1; 
    for(int i=1;i<=n;i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    int ans = fact[n];
    ans %= MOD;
    ans *= modInv(fact[r]);
    ans %= MOD;
    ans *= modInv(fact[n - r]);
    ans %= MOD;
    return ans;
    // return (fact[n] * modInv(fact[r]) % MOD * modInv(fact[n - r]) % MOD) % MOD; 

}
int32_t main() {
    int t = 1;
    // cin >> t;
    // cout << ncr_calc(950, 100) << endl;
    // return 0;
    while(t--) {
        int n, x, pos;
        cin >> n >> x >> pos;
        vi tot;
        int a = 0, b = n;
        while(a < b) {
            int mid = (a + b) / 2;
            tot.pb(mid);
            if(mid <= pos) a = mid + 1;
            else if(mid > pos) b = mid;
            // else break;
        }
        // for(auto i : tot) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // tot.pop_back();
        // if(tot.size() == 0) cout << solve(n - 1) << endl;
        // else {
            int gr = 0, le = 0;
            for(int i=0;i<tot.size();i++) {
                if(tot[i] > pos) gr++;
                else if(tot[i] < pos) le++;
            }
            if(n - x < gr || x - 1 < le) cout << 0 << endl;
            else {
                int temp;
                int ans1 = ncr_calc(n - x, gr);
                temp = solve(gr);
                ans1 *= temp;
                ans1 %= MOD;
                int ans2 = ncr_calc(x - 1, le);
                temp = solve(le);
                ans2 *= temp;
                ans2 %= MOD;
                int ans3 = solve(n - gr - le - 1);
                int ans = (ans1 * ans2) % MOD;
                ans = (ans * ans3) % MOD;
                cout << ans << endl;
            }
        // }
    }
    return 0;
}