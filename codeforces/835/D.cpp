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

int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;
        }
        dbg(dp);
        for(int i=0;i+1<n;i++) {
            if(s[i] == s[i + 1]) dp[i][i + 1] = 2;
        }
        dbg(dp);
        for(int len=3;len<=n;len++) {
            for(int i=0;i<n;i++) {
                int j = i + len - 1;
                if(j >= n) break;
                int mid = (i + j) / 2;
                if(s[i] != s[j] || !dp[i + 1][j - 1]) continue;
                dbg(i, j);
                dp[i][j] = 1;
                if(len % 2) {
                    if(dp[i][mid - 1] && dp[mid + 1][j]) {
                        assert(dp[i][mid - 1] == dp[mid + 1][j]);
                        dp[i][j] = dp[i][mid - 1] + 1;
                    }
                } else {
                    if(dp[i][mid] && dp[mid + 1][j]) {
                        assert(dp[i][mid] == dp[mid + 1][j]);
                        dp[i][j] = dp[i][mid] + 1;
                    }
                }
            }
        }
        dbg(dp);
        vector<int> ans(n + 1);
        for(int len=1;len<=n;len++) {
            for(int i=0;i<n;i++) {
                int j = i + len - 1;
                if(j >= n) break;
                ans[dp[i][j]]++;
            }
        }
        dbg(ans);
        for(int i=n-1;i>=1;i--) {
            ans[i] += ans[i + 1];
        }
        dbg(ans);
        for(int i=1;i<=n;i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}