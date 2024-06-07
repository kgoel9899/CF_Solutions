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

int solve(int curr, int amt, int m, int x, vector<int>& c, vector<int>& h) {
    if(curr == m) return 0;
    int op1 = solve(curr + 1, amt + x, m, x, c, h);
    int op2 = -INF;
    if(c[curr] <= amt) op2 = h[curr] + solve(curr + 1, amt + x - c[curr], m, x, c, h);
    return max(op1, op2);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int m, x;
        cin >> m >> x;
        vector<int> c(m + 1), h(m + 1);
        int s = 0;
        for(int i=1;i<=m;i++) {
            cin >> c[i] >> h[i];
            s += h[i];
        }
        // cout << solve(0, 0, m, x, c, h) << endl;
        vector<vector<int>> dp(m + 1, vector<int>(s + 1, INF));
        dp[0][0] = 0;
        for(int i=1;i<=m;i++) {
            for(int j=0;j<=s;j++) {
                dp[i][j] = dp[i - 1][j];
                int tot = (i - 1) * x;
                if(j >= h[i] && tot - dp[i - 1][j - h[i]] >= c[i]) dp[i][j] = min(dp[i][j], c[i] + dp[i - 1][j - h[i]]);
            }
        }
        for(int j=s;j>=0;j--) {
            if(dp[m][j] != INF) {
                cout << j << endl;
                break;
            }
        }
    }
}