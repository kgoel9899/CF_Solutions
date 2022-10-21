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

int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
            for(int j=0;j<m;j++) {
                if(v[i][j] == 'X') {
                    x = i;
                    y = j;
                }
            }
        }
        vector<vector<int>> dist(n, vector<int>(m, INF));
        queue<pair<int, int>> q;
        q.push({x, y});
        dist[x][y] = 0;
        vector<pair<int, int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            for(auto i : dirs) {
                int nx = i.first + f.first;
                int ny = i.second + f.second;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == INF && v[nx][ny] == '.') {
                    dist[nx][ny] = 1 + dist[f.first][f.second];
                    q.push({nx, ny});
                }
            }
        }
        string s = "DLRU";
        string ans = "";
        int ok = 1;
        while(k--) {
            int nx = x + 1, ny = y;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] <= k) {
                ans += 'D';
                x = nx;
                y = ny;
                continue;
            }
            nx = x, ny = y - 1;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] <= k) {
                ans += 'L';
                x = nx;
                y = ny;
                continue;
            }
            nx = x, ny = y + 1;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] <= k) {
                ans += 'R';
                x = nx;
                y = ny;
                continue;
            }
            nx = x - 1, ny = y;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] <= k) {
                ans += 'U';
                x = nx;
                y = ny;
                continue;
            }
            ok = 0;
            break;
        }
        if(ok) cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
}