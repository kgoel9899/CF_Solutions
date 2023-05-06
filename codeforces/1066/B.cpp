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

int n, r;
vector<int> v;
vector<vector<int>> dp;
int solve(int curr, int last) {
    if(curr == n + 1) {
        if(last == n) return 0;
        else return INF;
    }
    if(dp[curr][last] != -1) return dp[curr][last];
    int op1 = solve(curr + 1, last);
    // dbg(curr, last, op1);
    int op2 = INF;
    if(v[curr]) {
        if(curr - r > last) return dp[curr][last] = INF;
        op2 = 1 + solve(curr + 1, min(n, curr + r - 1));
    }
    return dp[curr][last] = min(op1, op2);
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> r;
        v.clear();
        v.resize(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> v[i];
        }
        dp.clear();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        int ans = solve(1, 0);
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
}