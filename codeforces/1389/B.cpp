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

int n, k, z;
vector<int> v;
vector<vector<vector<int>>> dp;
int solve(int curr, int left, bool move_left) {
    int left_done = z - left;
    int moves = curr + left_done * 2;
    // cout << curr << " " << left << " " << move_left << " " << moves << endl;
    if(moves == k) return 0;
    assert(moves < k);
    if(dp[curr][left][move_left] != -1) return dp[curr][left][move_left];
    if(move_left) return dp[curr][left][move_left] = v[curr + 1] + solve(curr + 1, left, false);
    else {
        int op1 = v[curr + 1] + solve(curr + 1, left, false);
        int op2 = 0;
        if(curr > 0 && left > 0) op2 = v[curr - 1] + solve(curr - 1, left - 1, true);
        return dp[curr][left][move_left] = max(op1, op2);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> k >> z;
        v.clear();
        v.resize(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        dp.clear();
        dp.resize(n + 1, vector<vector<int>>(z + 1, vector<int>(2, -1)));
        cout << v[0] + solve(0, z, false) << endl;
    }
}
// 1 - 2 - 3 - 2 - 3 - 4 - 3 - 4