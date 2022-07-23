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
bool dfs(int i, int j, int pi, int pj, int n, int m, char& orig, vector<string>& v, vector<vector<int>>& vis) {
    vis[i][j] = 1;
    for(auto k : dirs) {
        int nx = i + k.first;
        int ny = j + k.second;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !(nx == pi && ny == pj) && v[nx][ny] == orig) {
            if(vis[nx][ny]) return true;
            if(dfs(nx, ny, i, j, n, m, orig, v, vis)) return true;
        }
    }
    return false;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> vis(n, vector<int>(m));
        bool ans = false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j]) continue;
                ans |= dfs(i, j, -1, -1, n, m, v[i][j], v, vis);
            }
        }
        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}