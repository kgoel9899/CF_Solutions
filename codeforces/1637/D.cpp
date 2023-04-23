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

// https://www.youtube.com/watch?v=7iYND5KjsqI
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        int s = 0, tot = 0;
        for(int i=1;i<=n;i++) {
            cin >> a[i];
            s += a[i] * a[i];
            tot += a[i];
        }
        for(int i=1;i<=n;i++) {
            cin >> b[i];
            s += b[i] * b[i];
            tot += b[i];
        }
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }
        vector<vector<int>> dp(n + 1, vector<int>(tot + 5));
        // dp[i][j] = is sum j possible with the first i elements
        dp[1][a[1]] = 1, dp[1][b[1]] = 1;
        for(int i=2;i<=n;i++) {
            for(int j=0;j<tot;j++) {
                dp[i][j] |= (j - a[i] >= 0 ? dp[i - 1][j - a[i]] : false);
                dp[i][j] |= (j - b[i] >= 0 ? dp[i - 1][j - b[i]] : false);
            }
        }
        int mn = INF;
        for(int i=0;i<tot;i++) {
            if(!dp[n][i]) continue;
            mn = min(mn, i * i + (tot - i) * (tot - i));
        }
        cout << (n - 2) * s + mn << endl;
    }
}