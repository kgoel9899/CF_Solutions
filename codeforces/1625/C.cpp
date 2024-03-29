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

// dp[i][k] = time to reach i if we removed k posts uptill now, post at ith (if any) is not removed

// final ans = min(dp[n][0] ...... dp[n][k]);

int n, l, k;
vector<int> d, s;
vector<vector<int>> dp;
int solve(int ind, int rem) {
    dbg(ind, rem);
    if(rem < 0) return INF;
    if(ind == 0) return 0;
    if(dp[ind][rem] != -1) return dp[ind][rem];
    int ans = INF;
    for(int i=ind-1;i>=max(0ll,ind-rem-1);i--) {
        // last board taken is i
        int removed = ind - i - 1;
        dbg(i, ind, rem, removed);
        ans = min(ans, s[i] * (d[ind] - d[i]) + solve(i, rem - removed));
    }
    return dp[ind][rem] = ans;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> l >> k;
        d.clear();
        d.resize(n);
        s.clear();
        s.resize(n);
        for(int i=0;i<n;i++) {
            cin >> d[i];
        }
        for(int i=0;i<n;i++) {
            cin >> s[i];
        }
        d.push_back(l);
        int ans = INF;
        dbg(d);
        dbg(s);
        dp.clear();
        dp.resize(n + 5, vector<int>(n + 5, -1));
        ans = min(ans, solve(n, k));
        cout << ans << endl;
    }
} 