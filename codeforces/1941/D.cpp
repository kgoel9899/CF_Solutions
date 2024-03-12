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

set<int> ans;
void solve(int curr, int pos, int n, int m, vector<pair<int, char>>& v, vector<vector<int>>& dp) {
    if(m == 0) {
        assert(curr == v.size());
        ans.insert(pos);
        dp[pos][m] = 1;
        return;
    }
    if(dp[pos][m]) return;
    int next = (pos + v[curr].first) % n;
    if(next == 0) next = n;
    int prev = (pos - v[curr].first + n) % n;
    if(prev == 0) prev = n;
    if(v[curr].second == '0') solve(curr + 1, next, n, m - 1, v, dp);
    else if(v[curr].second == '1') solve(curr + 1, prev, n, m - 1, v, dp);
    else {
        solve(curr + 1, next, n, m - 1, v, dp);
        solve(curr + 1, prev, n, m - 1, v, dp);
    }
    dp[pos][m] = 1;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, m, x;
        cin >> n >> m >> x;
        vector<pair<int, char>> v(m);
        for(int i=0;i<m;i++) {
            cin >> v[i].first >> v[i].second;
        }
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        ans.clear();
        solve(0, x, n, m, v, dp);
        dbg(ans);
        cout << ans.size() << endl;
        for(auto& i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}