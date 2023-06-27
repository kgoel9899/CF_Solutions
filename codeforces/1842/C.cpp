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

map<int, vector<int>> m;
vector<vector<int>> dp;
int solve(int curr, int n, int on, vector<int>& v) {
    if(curr == n) return 0;
    if(dp[curr][on] != -1) return dp[curr][on];
    int ans = 0;
    if(on) {
        ans = solve(curr + 1, n, 0, v);
        int ind = upper_bound(all(m[v[curr]]), curr) - m[v[curr]].begin();
        if(ind < m[v[curr]].size()) ans = max(ans, m[v[curr]][ind] - curr + solve(m[v[curr]][ind], n, 1, v));
    } else {
        ans = solve(curr + 1, n, 0, v);
        int ind = upper_bound(all(m[v[curr]]), curr) - m[v[curr]].begin();
        if(ind < m[v[curr]].size()) ans = max(ans, m[v[curr]][ind] - curr + 1 + solve(m[v[curr]][ind], n, 1, v));
    }
    return dp[curr][on] = ans;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        m.clear();
        for(int i=0;i<n;i++) {
            cin >> v[i];
            m[v[i]].push_back(i);
        }
        dp.clear();
        dp.resize(n, vector<int>(2, -1));
        cout << solve(0, n, 0, v) << endl;
    }
}