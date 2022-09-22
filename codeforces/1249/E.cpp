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

int n, c;
vector<int> a, b, dp, dp1, dp2;
int solve(int curr) {
    if(curr == 0) return dp[curr] = 0;
    if(dp[curr] != -1) return dp[curr];
    int op1 = INF, op2 = INF;
    int s1 = 0, s2 = 0;
    for(int i=curr-1;i>=0;i--) {
        s1 += b[i];
        s2 += a[i];
        op1 = min(op1, c + s1 + solve(i));
        op2 = min(op2, s2 + solve(i));
    }
    return dp[curr] = min(op1, op2);
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> c;
        a.clear();
        a.resize(n);
        b.clear();
        b.resize(n);
        for(int i=0;i<n-1;i++) {
            cin >> a[i];
        }
        for(int i=0;i<n-1;i++) {
            cin >> b[i];
        }
        dp1.clear();
        dp1.resize(n);
        dp2.clear();
        dp2.resize(n);
        dp2[0] = c;
        for(int i=1;i<n;i++) {
            dp1[i] = a[i - 1] + min(dp1[i - 1], dp2[i - 1]);
            dp2[i] = b[i - 1] + min(dp1[i - 1] + c, dp2[i - 1]);
        }

        // dp.clear();
        // dp.resize(n, INF);
        // dp[0] = 0;
        // for(int i=1;i<n;i++) {
        //     int s1 = 0, s2 = 0;
        //     for(int j=i-1;j>=0;j--) {
        //         s1 += b[j];
        //         s2 += a[j];
        //         dp[i] = min({dp[i], c + s1 + dp[j], s2 + dp[j]});
        //     }
        // }

        // dp.resize(n, -1);
        // solve(n - 1);

        for(int i=0;i<n;i++) {
            cout << min(dp1[i], dp2[i]) << " ";
        }
    }
}