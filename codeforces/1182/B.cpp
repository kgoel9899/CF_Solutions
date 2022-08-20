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
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int ct = 0, x, y;
        for(int i=1;i<n-1;i++) {
            for(int j=1;j<m-1;j++) {
                if(v[i][j] == '*' && v[i - 1][j] == '*' && v[i + 1][j] == '*' && v[i][j - 1] == '*' && v[i][j + 1] == '*') {
                    ct++;
                    x = i;
                    y = j;
                }
            }
        }
        if(ct != 1) {
            cout << "NO" << endl;
            continue;
        }
        int a = 0, b = 0, c = 0, d = 0;
        for(int i=x-1;i>=0;i--) {
            if(v[i][y] != '*') break;
            a++;
            v[i][y] = '.';
        }
        for(int i=x+1;i<n;i++) {
            if(v[i][y] != '*') break;
            b++;
            v[i][y] = '.';
        }
        for(int i=y-1;i>=0;i--) {
            if(v[x][i] != '*') break;
            c++;
            v[x][i] = '.';
        }
        for(int i=y+1;i<m;i++) {
            if(v[x][i] != '*') break;
            d++;
            v[x][i] = '.';
        }
        v[x][y] = '.';
        dbg(v);
        int ok = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(v[i][j] == '*') ok = 0;
            }
        }
        if(ok && a && b && c && d) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}