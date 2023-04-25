#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
// #define int long long
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
vector<int> v;
int dp[5001][5001][2];
int solve(int l, int r, int col) {
    if(l == r) return 0;
    if(dp[l][r][col] != -1) return dp[l][r][col];
    if(col == 0) return dp[l][r][col] = min((v[l + 1] != v[l]) + solve(l + 1, r, 0), (v[r] != v[l]) + solve(l + 1, r, 1));
    else return dp[l][r][col] = min((v[r] != v[r - 1]) + solve(l, r - 1, 1), (v[r] != v[l]) + solve(l, r - 1, 0));
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        v.clear();
        v.resize(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        memset(dp, -1, sizeof dp);
        cout << min(solve(0, n - 1, 0), solve(0, n - 1, 1)) << endl;
    }
}