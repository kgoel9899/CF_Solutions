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

int n, k;
vector<int> v;
vector<vector<int>> dp;
int solve(int curr, int left) {
    if(curr == n) return left == 0;
    if(left < 0) return 0;
    if(dp[curr][left] != -1) return dp[curr][left];
    int ans = 0;
    for(int i=0;i<=v[curr];i++) {
        ans += solve(curr + 1, left - i);
        ans %= MOD;
    }
    return dp[curr][left] = ans;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> k;
        v.clear();
        v.resize(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        dp.clear();
        dp.resize(n + 1, vector<int>(k + 1));
        for(int i=0;i<=n;i++) {
            dp[i][0] = 1;
        }
        for(int i=0;i<=k;i++) {
            dp[0][i] = 1;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=k;j++) {
                // sum from dp[i - 1][j - min(v[i - 1], j)] .. dp[i - 1][j]
                // for(int kk=0;kk<=min(v[i - 1], j);kk++) {
                //     dp[i][j] += dp[i - 1][j - kk];
                //     dp[i][j] %= MOD;
                // }

                int kk = j - v[i - 1];
                if(kk > 0) dp[i][j] += dp[i - 1][j] - dp[i - 1][kk - 1] + MOD;
                else dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
                if(i != n) {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= MOD;
                }
            }
        }
        cout << dp[n][k] << endl;

        // dp.resize(n, vector<int>(k + 1, -1));
        // cout << solve(0, k) << endl;
    }
}