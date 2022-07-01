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
// dp[i][k] = till ith row a xor of k is possible or not
pair<int, int> solve(int ind, int xr) {
    if(ind == n) return {xr != 0, 1};
    if(dp[ind][xr].first != -1) return dp[ind][xr];
    int save = -1, ans = 0;
    for(int i=0;i<m;i++) {
        if(solve(ind + 1, xr ^ v[ind][i]).first > 0) {
            save = i;
            ans = 1;
            break;
        }
    }
    return dp[ind][xr] = {ans, save};
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
        dp.resize(n + 1, vector<pair<int, int>>(1024));
        dp[0][0] = {1, -1}; // we don't have anything, xor 0 is possible and index = -1
        for(int i=1;i<=n;i++) {
            for(int j=0;j<1024;j++) {
                bool ans = false;
                int ind = -1;
                for(int k=1;k<=m;k++) {
                    if(dp[i - 1][j ^ v[i - 1][k - 1]].first) {
                        ans = true;
                        ind = k;
                    }
                }
                dp[i][j] = {ans, ind};
            }
        }
        bool ans = false;
        dbg(dp);
        int xr = 0;
        for(int i=1;i<1024;i++) {
            if(dp[n][i].first) {
                ans = true;
                xr = i;
            }
        }
        dbg(ans, xr);
        if(ans) {
            assert(xr != 0);
            cout << "TAK" << endl;
            vector<int> prt;
            int row = n;
            while(row > 0) {
                int curr = dp[row][xr].second;
                prt.push_back(curr);
                xr ^= v[row - 1][curr - 1];
                row--;
            }
            reverse(all(prt));
            for(auto i : prt) {
                cout << i << " ";
            }
            cout << endl;
        } else cout << "NIE" << endl;
        
        // dp.resize(n + 1, vector<pair<int, int>>(1024, {-1, -1}));
        // pair<int, int> ans = solve(0, 0);
        // // dbg(dp);
        // if(ans.first) {
        //     cout << "TAK" << endl;
        //     int row = 0, xr = 0;
        //     while(row < n) {
        //         int curr = dp[row][xr].second;
        //         cout << curr + 1 << " ";
        //         xr ^= v[row][curr];
        //         row++;
        //     }
        //     cout << endl;
        // } else cout << "NIE" << endl;
    }
}