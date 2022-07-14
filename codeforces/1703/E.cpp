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

int cost(string& a, string& b, string& c, string& d, int n) {
    int ans = 0;
    for(int i=1;i<n-1;i++) {
        int ct = 0;
        if(b[i] != a[i]) ct++;
        if(c[i] != a[i]) ct++;
        if(d[i] != a[i]) ct++;
        ans += min(4 - ct, ct);
    }
    return ans;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int ans = 0;
        int row = 0, col = 0;
        for(int i=0;i<n-row;i++,row++) {
            string a = "";
            for(int j=col;j<n-col;j++) {
                a += v[row][j];
            }
            string b = "";
            for(int j=row;j<n-row;j++) {
                b += v[j][n - col - 1];
            }
            string c = "";
            for(int j=n-col-1;j>=col;j--) {
                c += v[n - row - 1][j];
            }
            string d = "";
            for(int j=n-row-1;j>=row;j--) {
                d += v[j][col];
            }
            col++;
            ans += cost(a, b, c, d, a.size());
            int o = 0, z = 0;
            if(a[0] == '0') z++;
            else o++;
            if(b[0] == '0') z++;
            else o++;
            if(c[0] == '0') z++;
            else o++;
            if(d[0] == '0') z++;
            else o++;
            ans += min(o, z);
        }
        cout << ans << endl;
    }
}