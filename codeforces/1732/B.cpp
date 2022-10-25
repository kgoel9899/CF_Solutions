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
string s;
vector<vector<vector<int>>> dp;
int solve(int curr, int turns, int last) {
    if(curr == n) return 0;
    if(dp[curr][turns][last] != -1) return dp[curr][turns][last];
    int here = s[curr] - '0';
    if(turns) here ^= 1;
    if(last == 0) {
        int op1 = solve(curr + 1, turns, here);
        int op2 = 1 + solve(curr + 1, (turns + 1) % 2, here ^ 1);
        return dp[curr][turns][last] = min(op1, op2);
    } else {
        if(here == 1) return dp[curr][turns][last] = solve(curr + 1, turns, here);
        else return dp[curr][turns][last] = 1 + solve(curr + 1, (turns + 1) % 2, here ^ 1);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n;
        cin >> s;
        dp.clear();
        dp.resize(n, vector<vector<int>>(2, vector<int>(2, -1)));
        cout << solve(0, 0, 0) << endl;
    }
}