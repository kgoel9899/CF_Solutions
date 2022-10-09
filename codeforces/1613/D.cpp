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
// vector<vector<vector<int>>> dp;
// int solve(int curr, int mex, int skip) {
//     if(curr == n) return 1;
//     if(dp[curr][mex][skip] != -1) return dp[curr][mex][skip];
//     int ans = 0;
//     if(skip) {
//         ans = solve(curr + 1, mex, skip);
//         if(v[curr] == mex - 1 || v[curr] == mex + 1) ans *= 2;
//         ans %= mod;
//     } else {
//         if(v[curr] == mex) ans = solve(curr + 1, mex, skip) + solve(curr + 1, mex + 1, skip);
//         else if(v[curr] == mex - 1) ans = 2 * solve(curr + 1, mex, skip);
//         else if(v[curr] == mex + 1) ans = solve(curr + 1, mex, skip) + solve(curr + 1, mex, 1);
//         else return dp[curr][mex][skip] = solve(curr + 1, mex, skip);
//         ans %= mod;
//     }
//     return dp[curr][mex][skip] = ans;
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
        vector<int> dp1(n + 2), dp2(n + 2);
        dp1[0] = 1; // counting empty subsequence, will be subtracted finally
        for(auto i : v) {
            // i am putting 'i'

            if(i) {
                dp2[i - 1] *= 2; // we have already skipped the kth element - 0011..i-2 i-2 ii i-2 i-2 + i put or not
                dp2[i - 1] += dp1[i - 1]; // skipping the kth element for the first time - 0011..i-2 i-2 + i put
                dp2[i - 1] %= mod;
            }

            dp1[i + 1] *= 2; // if the mex is already 'i + 1' then we can either put i or dont put it - 0011..ii + i put or not
            dp1[i + 1] += dp1[i]; // previously the mex was i and after putting i it will be i + 1 - 0011..i-1 + i put
            dp1[i + 1] %= mod;

            dp2[i + 1] *= 2; // we have already skipped the kth element - 0011..ii i+2 i+2 + i put or not
            dp2[i + 1] %= mod;
        }
        int ans = 0;
        for(int i=0;i<=n+1;i++) {
            ans += dp1[i] + dp2[i];
            ans %= mod;
        }
        cout << (ans - 1 + mod) % mod << endl;

        // dp.clear();
        // dp.resize(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));

        // // int ans = 0;
        // // for(int i=0;i<n;i++) {
        // //     if(v[i] == 0) ans += solve(i + 1, 1, 0);
        // //     else if(v[i] == 1) ans += solve(i + 1, 0, 1);
        // //     ans %= mod;
        // // }
        // // cout << ans << endl;

        // cout << solve(0, 0, 0) - 1 << endl;
    }
}
// 4
// 0 1 2 3
// 0
// 0 1
// 0 1 2
// 0 1 2 3
// 0 2
// 0 1 3

// 3
// 0 1 3
// 0
// 0 1
// 0 1 3
// 1