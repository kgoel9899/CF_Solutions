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
// map<vector<int>, int> dp;
// int solve(int curr, int prev, int skip) {
//     if(curr == n) {
//         if(prev == -1) return 0;
//         else return 1;
//     }
//     if(dp.find({curr, prev, skip}) != dp.end()) return dp[{curr, prev, skip}];
//     int ans = 0;
//     ans += solve(curr + 1, prev, skip);
//     if(v[curr] == prev) ans += solve(curr + 1, v[curr], skip);
//     ans %= mod;
//     if(v[curr] == prev + 2) {
//         if(skip == -1 || v[curr] == skip + 1) ans += solve(curr + 1, v[curr], prev + 1);
//     }
//     else if(v[curr] == prev - 2 && skip != -1) ans += solve(curr + 1, v[curr], skip);
//     else if(v[curr] == prev + 1 && skip == -1) ans += solve(curr + 1, v[curr], skip);
//     ans %= mod;
//     return dp[{curr, prev, skip}] = ans;
// }
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n;
        v.clear();
        v.resize(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<int> dp1(n + 2, 0), dp2(n + 2, 0);
        dp1[0] = 1;
        for(auto i : v) {
            // i am putting i
            if(i > 0) {
                dp2[i - 1] = dp1[i - 1] + 2 * dp2[i - 1];
                dp2[i - 1] %= mod;
            }
            dp1[i + 1] = dp1[i] + 2 * dp1[i + 1];
            dp1[i + 1] %= mod;
            dp2[i + 1] = 2 * dp2[i + 1];
            dp2[i + 1] %= mod;
        }
        int ans = 0;
        for(int i=0;i<=n+1;i++) {
            ans += dp1[i] + dp2[i];
            ans %= mod;
        }
        cout << (ans - 1 + mod) % mod << endl;
        // cout << solve(0, -1, -1) << endl;
    }
}