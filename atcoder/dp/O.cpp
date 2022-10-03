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

#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }

int n;
vector<vector<int>> v;
vector<int> dp;
int solve(int mask) {
    if(mask == (1 << n) - 1) return 1;
    if(dp[mask] != -1) return dp[mask];
    int ct = __builtin_popcount(mask);
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(((mask >> i) & 1) == 1) continue;
        if(v[ct][i]) {
            ans += solve(mask | (1 << i));
            ans %= MOD;
        }
    }
    return dp[mask] = ans;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        v.clear();
        v.resize(n, vector<int>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> v[i][j];
            }
        }
        dp.clear();
        dp.resize((1 << n), -1);
        cout << solve(0) << endl;
    }
}