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
vector<string> v;
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y, vector<vector<int>>& vis) {
    vis[x][y] = 1;
    for(auto& i : dirs) {
        int nx = x + i.first;
        int ny = y + i.second;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && v[nx][ny] == '#') dfs(nx, ny, vis);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m;
        v.clear();
        v.resize(n);
        int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
        int tot = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            for(int j=0;j<m;j++) {
                if(v[i][j] == '#') {
                    if(x1 == -1) {
                        x1 = i;
                        y1 = j;
                    } else {
                        x2 = i;
                        y2 = j;
                    }
                    tot++;
                }
            }
        }
        if(tot <= 2) {
            cout << -1 << endl;
            continue;
        }
        int ok = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(v[i][j] == '#') {
                    vector<vector<int>> vis(n, vector<int>(m));
                    v[i][j] = '.';
                    if(i == x1 && j == y1) dfs(x2, y2, vis);
                    else if(i == x2 && j == y2) dfs(x1, y1, vis);
                    else dfs(x1, y1, vis);
                    for(int k=0;k<n;k++) {
                        for(int l=0;l<m;l++) {
                            if(v[k][l] == '#' && !vis[k][l]) ok = 1;
                        }
                    }
                    v[i][j] = '#';
                }
            }
        }
        if(ok) cout << 1 << endl;
        else cout << 2 << endl;
    }
}