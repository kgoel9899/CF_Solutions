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
vector<int> v;
vector<vector<int>> dp, sum;
int solve(int l, int r) {
    if(l == r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int ans = INF;
    for(int i=l;i<r;i++) {
        ans = min(ans, solve(l, i) + solve(i + 1, r) + sum[l][r]);
    }
    return dp[l][r] = ans;
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
        dp.clear();
        dp.resize(n, vector<int>(n, -1));
        sum.clear();
        sum.resize(n, vector<int>(n));
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                sum[i][j] = v[j] + (j > 0 ? sum[i][j - 1] : 0);
            }
        }
        cout << solve(0, n - 1) << endl;
    }
}