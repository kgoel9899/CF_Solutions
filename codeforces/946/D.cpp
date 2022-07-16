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

int n, m, k;
vector<string> v;
vector<vector<int>> pref, mint, dp;
int solve(int curr, int skip) {
    if(skip < 0) return INF;
    if(curr == n) return 0;
    if(dp[curr][skip] != -1) return dp[curr][skip];
    int tot = pref[curr][m - 1];
    int ans = INF;
    for(int i=0;i<=tot;i++) {
        ans = min(ans, mint[curr][tot - i] + solve(curr + 1, skip - i));
    }
    return dp[curr][skip] = ans;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m >> k;
        v.clear();
        v.resize(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        pref.clear();
        pref.resize(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            pref[i][0] = v[i][0] - '0';
            for(int j=1;j<m;j++) {
                pref[i][j] = pref[i][j - 1] + (v[i][j] - '0');
            }
        }
        mint.clear();
        mint.resize(n, vector<int>(m + 1, INF));
        for(int i=0;i<n;i++) {
            mint[i][0] = 0;
            for(int j=0;j<m;j++) {
                if(v[i][j] == '0') continue;
                for(int kk=j;kk<m;kk++) {
                    int curr = pref[i][kk];
                    if(j) curr -= pref[i][j - 1];
                    mint[i][curr] = min(mint[i][curr], kk - j + 1);
                }
            }
        }
        // dbg(mint);
        dp.clear();
        dp.resize(n, vector<int>(k + 1, -1));
        cout << solve(0, k) << endl;
    }
}