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

int n, w, s;
vector<int> wt, v;
vector<vector<int>> dp;
int solve(int curr, int val) {
    if(val <= 0) return 0;
    if(curr == n) return INF;
    if(dp[curr][val] != -1) return dp[curr][val];
    return dp[curr][val] = min(solve(curr + 1, val), wt[curr] + solve(curr + 1, val - v[curr]));
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> w;
        s = 0;
        wt.clear();
        wt.resize(n);
        v.clear();
        v.resize(n);
        for(int i=0;i<n;i++) {
            cin >> wt[i] >> v[i];
            s += v[i];
        }
        dp.clear();
        dp.resize(n + 1, vector<int>(s + 1, INF));
        for(int i=0;i<=n;i++) {
            dp[i][0] = 0;
        }
        for(int i=1;i<=n;i++) {
            for(int j=s;j>=1;j--) {
                dp[i][j] = dp[i - 1][j];
                if(j - v[i - 1] >= 0) dp[i][j] = min(dp[i][j], wt[i - 1] + dp[i - 1][j - v[i - 1]]);
            }
        }
        int ans = 0;
        for(int i=0;i<=s;i++) {
            if(dp[n][i] <= w) ans = i;
        }
        cout << ans << endl;

        // dp.resize(n, vector<int>(s + 1, -1));
        // int ans = 0;
        // for(int i=0;i<=s;i++) {
        //     if(solve(0, i) <= w) ans = i;
        // }
        // cout << ans << endl;
    }
}