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

vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dfs(int x, int y, int n, int m, vector<vector<int>>& vis, vector<string>& v) {
    vis[x][y] = 0;
    int ans = 0;
    for(auto i : dirs) {
        int nx = x + i.first;
        int ny = y + i.second;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == -1) {
            if(v[nx][ny] == '*') vis[x][y]++;
            else {
                dfs(nx, ny, n, m, vis, v);
                vis[x][y] += vis[nx][ny];
            }
            ans = max(ans, vis[x][y]);
        }
    }
    return ans;
}
void dfs2(int ans, int x, int y, int n, int m, vector<vector<int>>& res, vector<string>& v) {
    res[x][y] = ans;
    dbg(x, y);
    for(auto i : dirs) {
        int nx = x + i.first;
        int ny = y + i.second;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && res[nx][ny] ==  -1 && v[nx][ny] == '.') dfs2(ans, nx, ny, n, m, res, v);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> vis(n, vector<int>(m, -1));
        vector<vector<int>> res(n, vector<int>(m, -1));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j] == -1 && v[i][j] == '.') {
                    int ans = dfs(i, j, n, m, vis, v);
                    dfs2(ans, i, j, n, m, res, v);
                }
            }
        }
        dbg(vis);
        dbg(res);
        while(k--) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            cout << res[x][y] << endl;
        }
    }
} 