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

// https://www.youtube.com/watch?v=2cdxTU_ByrE
int n, s;
vector<int> v, x, y;
vector<vector<int>> dp;
int solve(int curr, int prev, int turn) {
    if(curr == n - 1) return prev * v[curr];
    if(dp[curr][turn] != -1) return dp[curr][turn];
    int p = prev * x[curr] + solve(curr + 1, y[curr], 0);
    int q = prev * y[curr] + solve(curr + 1, x[curr], 1);
    return dp[curr][turn] = min(p, q);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> s;
        v.clear();
        v.resize(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        x.clear();
        x.resize(n);
        y.clear();
        y.resize(n);
        dp.clear();
        dp.resize(n, vector<int>(2, -1));
        for(int i=1;i<n-1;i++) {
            if(v[i] >= 2 * s) {
                x[i] = s;
                y[i] = v[i] - s;
            } else if(v[i] >= s) {
                x[i] = v[i] - s;
                y[i] = s;
            } else {
                x[i] = 0;
                y[i] = v[i];
            }
        }
        int p = v[0] * x[1] + solve(2, y[1], 0);
        int q = v[0] * y[1] + solve(2, x[1], 1);
        cout << min(p, q) << endl;
    }
}