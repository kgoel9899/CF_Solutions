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

pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool solve(int x, int y, int n, int m, vector<string>& v, vector<vector<bool>>& vis) {
    if(x == n - 1 && y == m - 1) return true;
    vis[x][y] = 1;
    bool ans = false;
    for(int i=0;i<4;i++) {
        int nx = x + dirs[i].first;
        int ny = y + dirs[i].second;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
            vis[nx][ny] = 1;
            if(v[nx][ny] == '<') ny--;
            else ny++;
            ans |= solve(nx, ny, n, m, v, vis);
        }
    }
    return ans;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, m;
        n = 2;
        cin >> m;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<bool>> vis(n, vector<bool>(m));
        if(solve(0, 0, n, m, v, vis)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}