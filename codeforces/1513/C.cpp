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

vector<vector<int>> dp;
int solve(int curr, int m) {
    if(m == 0) return 1;
    if(dp[curr][m] != -1) return dp[curr][m];
    if(curr == 9) return dp[curr][m] = (solve(0, m - 1) + solve(1, m - 1)) % MOD;
    else return dp[curr][m] = solve(curr + 1, m - 1);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    const int N = 2e5 + 5;
    dp.clear();
    dp.resize(10, vector<int>(N, 1));
    for(int j=1;j<N;j++) {
        for(int i=0;i<10;i++) {
            if(i == 9) dp[i][j] = (dp[1][j - 1] + dp[0][j - 1]) % MOD;
            else dp[i][j] = dp[i + 1][j - 1];
        }
    }
    // dp.resize(10, vector<int>(N, -1));
    while(tt--) {
        int n, m;
        cin >> n >> m;
        string s = to_string(n);
        int ans = 0;
        for(auto& i : s) {
            ans += dp[i - '0'][m];
            // ans += solve(i - '0', m);
            ans %= MOD;
        }
        cout << ans << endl;
    }
}