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

vector<vector<int>> dp;
int solve(int curr, int ind, int n, vector<int>& temp, vector<vector<int>>& v) {
    if(ind == 3) return 0;
    if(curr == n) return -INF;
    if(dp[curr][ind] != -1) return dp[curr][ind];
    int op1 = solve(curr + 1, ind, n, temp, v);
    int op2 = v[temp[ind]][curr] + solve(curr + 1, ind + 1, n, temp, v);
    return dp[curr][ind] = max(op1, op2);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<vector<int>> v(3, vector<int>(n));
        for(int i=0;i<3;i++) {
            for(int j=0;j<n;j++) {
                cin >> v[i][j];
            }
        }
        vector<int> temp = {0, 1, 2};
        int ans = 0;
        do {
            dp.clear();
            dp.resize(n, vector<int>(3, -1));
            ans = max(ans, solve(0, 0, n, temp, v));
        } while(next_permutation(all(temp)));
        cout << ans << endl;
    }
}