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


int n, m;
vector<vector<int>> v;
vector<vector<pair<int, int>>> dp;
pair<int, int> solve(int curr, int xr) {
    if(curr == n) return {xr != 0, -1};
    if(dp[curr][xr].first != -1) return dp[curr][xr];
    int ind = -1, ok = 0;
    for(int i=0;i<m;i++) {
        if(solve(curr + 1, xr ^ v[curr][i]).first) {
            ind = i;
            ok = 1;
            break;
        }
    }
    return dp[curr][xr] = {ok, ind};
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m;
        v.clear();
        v.resize(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> v[i][j];
            }
        }
        dp.clear();
        dp.resize(n, vector<pair<int, int>>(1025, {-1, -1}));
        pair<int, int> ans = solve(0, 0);
        if(ans.first) {
            cout << "TAK" << endl;
            int row = 0, xr = 0;
            while(row < n) {
                int ind = dp[row][xr].second;
                cout << ind + 1 << " ";
                xr ^= v[row][ind];
                row++;
            }
        } else cout << "NIE" << endl;

        // int xr = 0;
        // for(int i=0;i<n;i++) {
        //     xr ^= v[i][0];
        // }
        // if(xr > 0) {
        //     cout << "TAK" << endl;
        //     for(int i=0;i<n;i++) {
        //         cout << 1 << " ";
        //     }
        //     cout << endl;
        // } else {
        //     int row = -1, col;
        //     for(int i=0;i<n;i++) {
        //         for(int j=1;j<m;j++) {
        //             if(v[i][j] != v[i][0]) {
        //                 row = i;
        //                 col = j;
        //             }
        //         }
        //     }
        //     if(row == -1) cout << "NIE" << endl;
        //     else {
        //         cout << "TAK" << endl;
        //         for(int i=0;i<n;i++) {
        //             if(i == row) cout << col + 1 << " ";
        //             else cout << 1 << " ";
        //         }
        //         cout << endl;
        //     }
        // }
    }
} 