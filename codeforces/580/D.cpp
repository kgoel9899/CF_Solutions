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

int n, m, k;
vector<int> sat;
vector<vector<int>> v, dp;
int solve(int mask, int last) {
    if(__builtin_popcountll(mask) == m) return 0;
    if(dp[mask][last] != -1) return dp[mask][last];
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(((mask >> i) & 1) == 1) continue;
        ans = max(ans, sat[i] + v[last][i + 1] + solve(mask | (1 << i), i + 1));
    }
    return dp[mask][last] = ans;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m >> k;
        sat.clear();
        sat.resize(n);
        for(int i=0;i<n;i++) {
            cin >> sat[i];
        }
        v.clear();
        v.resize(n + 1, vector<int>(n + 1));
        while(k--) {
            int x, y, c;
            cin >> x >> y >> c;
            v[y][x] = c;
        }
        dp.clear();
        dp.resize((1 << n) - 1, vector<int>(n + 1, -1));
        cout << solve(0, 0) << endl;
    }
}