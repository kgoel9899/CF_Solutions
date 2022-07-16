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

// hint from editorial
vector<int> sz;
vector<vector<int>> dp;
bool solve(int ind, int first, int req, int n) {
    if(first == req) return true;
    if(first > req) return false;
    if(ind == n) return false;
    if(dp[ind][first] != -1) return dp[ind][first];
    return dp[ind][first] = solve(ind + 1, first + sz[ind], req, n) || solve(ind + 1, first, req, n);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(2 * n);
        for(int i=0;i<2*n;i++) {
            cin >> v[i];
        }
        sz.clear();
        vector<int> vis(2 * n + 1);
        int val = 2 * n, last = 2 * n;
        for(int i=2*n-1;i>=0;i--) {
            vis[v[i]] = 1;
            if(v[i] == val) {
                for(int j=val-1;j>=1;j--) {
                    if(vis[j] == 0) {
                        val = j;
                        break;
                    }
                }
                sz.push_back(last - i);
                last = i;
            }
        }
        reverse(all(sz));
        dp.clear();
        dp.resize(sz.size(), vector<int>(n + 1, -1));
        if(solve(0, 0, n, sz.size())) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}