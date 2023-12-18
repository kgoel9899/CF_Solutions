#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define endl "\n"
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

int n, m;
int dp[102][102];
vector<int> r, b;
int solve(int i, int j) {
    if(i == n && j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int op1 = (i < n) ? r[i] + solve(i + 1, j) : 0;
    int op2 = (j < m) ? b[j] + solve(i, j + 1) : 0;
    return dp[i][j] = max({0ll, op1, op2});
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n;
        r.clear();
        r.resize(n);
        for(int i=0;i<n;i++) {
            cin >> r[i];
        }
        cin >> m;
        b.clear();
        b.resize(m);
        for(int i=0;i<m;i++) {
            cin >> b[i];
        }
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0) << endl;
    }
}