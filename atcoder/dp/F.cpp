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

string s, t, ans;
void solve(int i, int j, string curr) {
    if(i == s.size() && j == t.size()) {
        if(curr.size() > ans.size()) ans = curr;
        return;
    }
    if(i > s.size() || j > t.size()) return;
    if(s[i] == t[j]) solve(i + 1, j + 1, curr + s[i]);
    else {
        solve(i + 1, j, curr);
        solve(i, j + 1, curr);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> s >> t;
        ans = "";
        // string curr = "";
        // solve(0, 0, curr);
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1)); // dp[i][j] = s[0..i-1] and t[0..j-1] length of lcs
        for(int i=1;i<=s.size();i++) {
            for(int j=1;j<=t.size();j++) {
                if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        // cout << dp[s.size()][t.size()] << endl;
        int i = s.size(), j = t.size();
        while(i > 0 && j > 0) {
            if(s[i - 1] == t[j - 1]) {
                ans += s[i - 1];
                i--;
                j--;
            } else {
                if(dp[i - 1][j] > dp[i][j - 1]) i--;
                else j--;
            }
        }
        reverse(all(ans));
        cout << ans << endl;
    }
}