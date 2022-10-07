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

int dp[101][101][2][2];
int solve(int ev, int odd, int parity, int turn) {
    if(ev + odd == 1) {
        if(turn == 0) {
            if(ev) return parity == 0;
            else return parity == 1;
        } else return parity == 0;
    }
    if(dp[ev][odd][parity][turn] != -1) return dp[ev][odd][parity][turn];
    if(turn == 0) {
        int op1 = -1, op2 = -1;
        if(odd) op1 = solve(ev, odd - 1, (parity + 1) % 2, turn ^ 1);
        if(ev) op2 = solve(ev - 1, odd, (parity + 2) % 2, turn ^ 1);
        if(op1 == 1 || op2 == 1) return dp[ev][odd][parity][turn] = 1;
        else return dp[ev][odd][parity][turn] = 0;
    } else {
        int op1 = -1, op2 = -1;
        if(odd) op1 = solve(ev, odd - 1, parity, turn ^ 1);
        if(ev) op2 = solve(ev - 1, odd, parity, turn ^ 1);
        if(op1 == 0 || op2 == 0) return dp[ev][odd][parity][turn] = 0;
        else return dp[ev][odd][parity][turn] = 1;
    }
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int odd = 0, ev = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            if(v[i] % 2) odd++;
            else ev++;
        }
        memset(dp, -1, sizeof dp);
        if(solve(ev, odd, 0, 0)) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}