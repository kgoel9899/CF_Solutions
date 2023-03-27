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
        int n, m, i1, j1, i2, j2;
        cin >> n >> m >> i1 >> j1 >> i2 >> j2;
        string s;
        cin >> s;
        int ans = 0;
        int ok = 0;
        for(int tot=0;tot<=4*n*m;tot++) {
            if(s == "DL") {
                int ch = min(n - i1, j1 - 1);
                int x = i2 - i1;
                int y = j1 - j2;
                if(x == y && x >= 0) {
                    ok = 1;
                    break;
                }
                i1 += ch;
                j1 -= ch;
                if(i1 == n && j1 == 1) s = "UR";
                else if(i1 == n) s = "UL";
                else s = "DR";
                ans++;
            } else if(s == "UL") {
                int ch = min(i1 - 1, j1 - 1);
                int x = i1 - i2;
                int y = j1 - j2;
                if(x == y && x >= 0) {
                    ok = 1;
                    break;
                }
                i1 -= ch;
                j1 -= ch;
                if(i1 == 1 && j1 == 1) s = "DR";
                else if(i1 == 1) s = "DL";
                else s = "UR";
                ans++;
            } else if(s == "UR") {
                int ch = min(i1 - 1, m - j1);
                int x = i1 - i2;
                int y = j2 - j1;
                if(x == y && x >= 0) {
                    ok = 1;
                    break;
                }
                i1 -= ch;
                j1 += ch;
                if(i1 == 1 && j1 == m) s = "DL";
                else if(i1 == 1) s = "DR";
                else s = "UL";
                ans++;
            } else {
                int ch = min(n - i1, m - j1);
                int x = i2 - i1;
                int y = j2 - j1;
                if(x == y && x >= 0) {
                    ok = 1;
                    break;
                }
                i1 += ch;
                j1 += ch;
                if(i1 == n && j1 == m) s = "UL";
                else if(i1 == n) s = "UR";
                else s = "DL";
                ans++;
            }
        }
        if(ok) cout << ans << endl;
        else cout << -1 << endl;
    }   
}