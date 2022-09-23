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
vector<vector<vector<int>>> dp;
int solve(int curr, int age, int dir) {
    if(age == 0) return 0;
    if(curr == -1 || curr == n) return 1;
    assert(curr >= 0 && curr < n);
    assert(age > 0);
    if(dp[curr][age][dir] != -1) return dp[curr][age][dir];
    if(dir) return dp[curr][age][dir] = (solve(curr + 1, age, 1) + solve(curr - 1, age - 1, 0)) % MOD;
    else return dp[curr][age][dir] = (solve(curr - 1, age, 0) + solve(curr + 1, age - 1, 1)) % MOD;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> k;
        dp.clear();
        dp.resize(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        cout << solve(0, k, 1) << endl;
    }
}