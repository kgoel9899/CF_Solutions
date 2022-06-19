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

int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> v[i][j];
            }
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2)));
        dp[0][0][0] = v[0][0];
        dp[0][0][1] = v[0][0];
        for(int i=1;i<n;i++) {
            dp[i][0][0] = dp[i - 1][0][0] + v[i][0];
            dp[i][0][1] = dp[i - 1][0][1] + v[i][0];
        }
        for(int i=1;i<m;i++) {
            dp[0][i][0] = dp[0][i - 1][0] + v[0][i];
            dp[0][i][1] = dp[0][i - 1][1] + v[0][i];
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                dp[i][j][0] = v[i][j] + min(dp[i - 1][j][0], dp[i][j - 1][0]);
                dp[i][j][1] = v[i][j] + max(dp[i - 1][j][1], dp[i][j - 1][1]);
            }
        }
        int d1 = abs(dp[n - 1][m - 1][0] - 0);
        int d2 = abs(dp[n - 1][m - 1][1] - 0);
        if(dp[n - 1][m - 1][0] <= 0 && 0 <= dp[n - 1][m - 1][1] && d1 % 2 == 0 && d2 % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}