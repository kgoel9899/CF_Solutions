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
        vector<set<pair<int, int>>> a;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(v[i][j] != '*') continue;
                int ok = 0;
                if(i + 1 < n && j + 1 < m) {
                    if(v[i][j] == '*' && v[i + 1][j] == '*' && v[i + 1][j + 1] == '*') {
                        v[i][j] = '1';
                        v[i + 1][j] = '1';
                        v[i + 1][j + 1] = '1';
                        ok = 1;
                        a.push_back({{i, j}, {i + 1, j}, {i + 1, j + 1}});
                    }
                }
                if(ok) continue;
                if(i + 1 < n && j - 1 >= 0) {
                    if(v[i][j] == '*' && v[i + 1][j] == '*' && v[i + 1][j - 1] == '*') {
                        v[i][j] = '1';
                        v[i + 1][j] = '1';
                        v[i + 1][j - 1] = '1';
                        ok = 1;
                        a.push_back({{i, j}, {i + 1, j}, {i + 1, j - 1}});
                    }
                }
                if(ok) continue;
                if(i - 1 >= 0 && j + 1 < m) {
                    if(v[i][j] == '*' && v[i - 1][j] == '*' && v[i - 1][j + 1] == '*') {
                        v[i][j] = '1';
                        v[i - 1][j] = '1';
                        v[i - 1][j + 1] = '1';
                        ok = 1;
                        a.push_back({{i, j}, {i - 1, j}, {i - 1, j + 1}});
                    }
                }
                if(ok) continue;
                if(i - 1 >= 0 && j - 1 >= 0) {
                    if(v[i][j] == '*' && v[i - 1][j] == '*' && v[i - 1][j - 1] == '*') {
                        v[i][j] = '1';
                        v[i - 1][j] = '1';
                        v[i - 1][j - 1] = '1';
                        ok = 1;
                        a.push_back({{i, j}, {i - 1, j}, {i - 1, j - 1}});
                    }
                }
            }
        }
        // dbg(v);
        int ok = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(v[i][j] == '*') ok = 0;
            }
        }
        if(!ok) {
            cout << "NO" << endl;
            continue;
        }
        // dbg(a);
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for(auto& i : a) {
            for(auto& j : i) {
                for(auto& k : dirs) {
                    int nx = j.first + k.first;
                    int ny = j.second + k.second;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == '1') {
                        if(i.find({nx, ny}) == i.end()) {
                            ok = 0;
                            break;
                        }
                    }
                }
                if(!ok) break;
            }
            if(!ok) break;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}