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
vector<vector<double>> v;
vector<double> dp;
double solve(int bitmask) {
    if(bitmask == (1 << n) - 1) return 1; // all fish alive, prob = 1
    if(dp[bitmask] > -0.9) return dp[bitmask]; // taking care of precision errors
    double ans = 0.0;
    for(int i=0;i<n;i++) {
        if(((bitmask >> i) & 1) == 1) {
            // already alive
            continue;
        }
        int prev = (bitmask | (1 << i));
        int alive = __builtin_popcountll(prev);
        int den = (alive * (alive - 1)) / 2; // nC2
        double prob = 0.0;
        for(int j=0;j<n;j++) {
            if(((prev >> j) & 1) == 1) {
                prob += v[j][i]; // ith fish died because of jth fish
            }
        }
        ans += (prob / den) * solve(prev);
    }
    return dp[bitmask] = ans;
}
int32_t main() {
    fast;
    int tt = 1;
    setpres;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        v.clear();
        v.resize(n, vector<double>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> v[i][j];
            }
        }
        dp.clear();
        dp.resize(1 << n, -1.0);
        for(int i=0;i<n;i++) {
            cout << solve(1 << i) << " "; // if bit is set, means alive
        }
    }
}