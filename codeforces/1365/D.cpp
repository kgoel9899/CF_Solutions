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
void update(int i, int j, vector<string>& v) {
    if(i >= 0 && i < n && j >= 0 && j < m && v[i][j] == '.') v[i][j] = '#';
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    int x = 1;
    while(tt--) {
        cin >> n >> m;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int good = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(v[i][j] == 'B') {
                    update(i + 1, j, v);
                    update(i - 1, j, v);
                    update(i, j + 1, v);
                    update(i, j - 1, v);
                } else if(v[i][j] == 'G') good++;
            }
        }
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        if(v[n - 1][m - 1] == '.') {
            q.push({n - 1, m - 1});
            v[n - 1][m - 1] = '#';
        }
        int bad = 0;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            for(auto i : dirs) {
                int nx = f.first + i.first;
                int ny = f.second + i.second;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#') {
                    if(v[nx][ny] == 'G') good--;
                    if(v[nx][ny] == 'B') {
                        bad = 1;
                        break;
                    }
                    v[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
            if(bad) break;
        }
        if(good == 0 && !bad) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}