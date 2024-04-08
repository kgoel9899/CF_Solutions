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
        int n, c, d;
        cin >> n >> c >> d;
        multiset<int> s;
        int mn = INF;
        for(int i=0;i<n*n;i++) {
            int x;
            cin >> x;
            mn = min(mn, x);
            s.insert(x);
        }
        vector<vector<int>> v(n, vector<int>(n));
        v[0][0] = mn;
        s.erase(s.find(mn));
        queue<pair<int, int>> q;
        q.push({0, 0});
        int ok = 1;
        dbg(s);
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            dbg(f.first, f.second);
            // c
            int nx = f.first + 1;
            int ny = f.second;
            if(nx < n) {
                dbg(1, nx, ny);
                int val = v[f.first][f.second] + c;
                dbg(val);
                if(!v[nx][ny]) {
                    if(s.find(val) == s.end()) {
                        ok = 0;
                        break;
                    }
                    dbg("found");
                    s.erase(s.find(val));
                    v[nx][ny] = val;
                    q.push({nx, ny});
                } else {
                    if(v[nx][ny] != val) {
                        ok = 0;
                        break;
                    }
                }
            }
            // d
            nx = f.first;
            ny = f.second + 1;
            if(ny < n) {
                dbg(2, nx, ny);
                int val = v[f.first][f.second] + d;
                if(!v[nx][ny]) {
                    if(s.find(val) == s.end()) {
                        ok = 0;
                        break;
                    }
                    s.erase(s.find(val));
                    v[nx][ny] = val;
                    q.push({nx, ny});
                } else {
                    if(v[nx][ny] != val) {
                        ok = 0;
                        break;
                    }
                }
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}