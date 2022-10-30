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
        int n, m;
        cin >> n >> m;
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        int x, y;
        cin >> x >> y;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int ans = 1;
        v[r][c] = '+';
        deque<vector<int>> q; // {x, y, left, right};
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        q.push_front({r, c, x, y});
        while(!q.empty()) {
            auto f = q.front();
            q.pop_front();
            for(auto& i : dirs) {
                int nx = i.first + f[0];
                int ny = i.second + f[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == '.') {
                    if(ny + 1 == f[1]) {
                        // left
                        if(f[2]) {
                            q.push_back({nx, ny, f[2] - 1, f[3]});
                            v[nx][ny] = '+';
                            ans++;
                        }
                    } else if(ny - 1 == f[1]) {
                        // right
                        if(f[3]) {
                            q.push_back({nx, ny, f[2], f[3] - 1});
                            v[nx][ny] = '+';
                            ans++;
                        }
                    } else {
                        // up/down
                        q.push_front({nx, ny, f[2], f[3]});
                        v[nx][ny] = '+';
                        ans++;
                    }
                }
            }
        }
        dbg(v);
        cout << ans << endl;
    }
}