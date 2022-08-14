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
        int n, m, k, x, y;
        cin >> n >> m >> k >> x >> y;
        vector<vector<int>> v(n, vector<int>(m));
        if(n == 1) {
            int per = m;
            int full = k / per;
            k %= per;
            for(int i=0;i<m;i++) {
                v[0][i] += full;
            }
            for(int i=0;i<m&&k>0;i++,k--) {
                v[0][i]++;
            }
        } else {
            int per = n * m + (n - 2) * m;
            dbg(per);
            int full = k / per;
            k %= per;
            dbg(per, full, k);
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if(i == 0 || i == n - 1) v[i][j] += full;
                    else v[i][j] += 2 * full;
                }
            }
            dbg(v);
            for(int i=0;i<n;i++) {
                for(int j=0;j<m&&k>0;j++,k--) {
                    v[i][j]++;
                }
            }
            dbg(v);
            dbg(k);
            for(int i=n-2;i>=0;i--) {
                for(int j=0;j<m&&k>0;j++,k--) {
                    v[i][j]++;
                }
            }
        }
        int mx = -INF, mn = INF;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                mx = max(mx, v[i][j]);
                mn = min(mn, v[i][j]);
            }
        }
        dbg(v);
        dbg(x - 1, y - 1);
        cout << mx << " " << mn << " " << v[x - 1][y - 1] << endl;
    }
}