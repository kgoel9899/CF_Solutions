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
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int good = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(v[i][j] == 'B') {
                    for(auto& k : dirs) {
                        int nx = i + k.first;
                        int ny = j + k.second;
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == '.') v[nx][ny] = '#';
                    }
                } else if(v[i][j] == 'G') good++;
            }
        }
        if(v[n - 1][m - 1] == '#') {
            if(good) cout << "No" << endl;
            else cout << "Yes" << endl;
            continue;
        }
        queue<pair<int, int>> q;
        q.push({n - 1, m - 1});
        v[n - 1][m - 1] = '#';
        int ok = 1;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            for(auto i : dirs) {
                int nx = f.first + i.first;
                int ny = f.second + i.second;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#') {
                    q.push({nx, ny});
                    if(v[nx][ny] == 'G') good--;
                    else if(v[nx][ny] == 'B') {
                        ok = 0;
                        break;
                    }
                    v[nx][ny] = '#';
                }
            }
            if(!ok) break;
        }
        if(!ok) cout << "No" << endl;
        else {
            if(good == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}  