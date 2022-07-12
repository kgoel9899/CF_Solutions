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

int n, k;
vector<int> v;
vector<vector<int>> dp;
int solve(int ind, int half) {
    if(ind == n) return 0;
    if(half >= 35) return 0;
    if(dp[ind][half] != -1) return dp[ind][half];
    return dp[ind][half] = max((v[ind] >> half) - k + solve(ind + 1, half), (v[ind] >> half) / 2 + solve(ind + 1, half + 1));
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> k;
        v.clear();
        v.resize(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        dp.clear();
        dp.resize(n, vector<int>(35, -1));
        cout << solve(0, 0) << endl;
    }
}