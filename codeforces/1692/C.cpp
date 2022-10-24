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

bool good(vector<string> v, int n, int r, int c) {
    if(v[r][c] != '#') return false;
    v[r][c] = '.';
    for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--) {
        if(v[i][j] != '#') return false;
        v[i][j] = '.';
    }
    for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++) {
        if(v[i][j] != '#') return false;
        v[i][j] = '.';
    }
    for(int i=r+1,j=c-1;i<n&&j>=0;i++,j--) {
        if(v[i][j] != '#') return false;
        v[i][j] = '.';
    }
    for(int i=r+1,j=c+1;i<n&&j<n;i++,j++) {
        if(v[i][j] != '#') return false;
        v[i][j] = '.';
    }
    int ok = 1;
    for(auto i : v) {
        for(auto j : i) {
            if(j == '#') ok = 0;
        }
    }
    return ok;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n = 8;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int ok = 0;
        for(int i=1;i<n-1;i++) {
            for(int j=1;j<n-1;j++) {
                if(good(v, n, i, j)) {
                    cout << i + 1 << " " << j + 1 << endl;
                    ok = 1;
                }
            }
        }
        assert(ok == 1);
    }
}