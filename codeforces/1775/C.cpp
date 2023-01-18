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
        int n, x;
        cin >> n >> x;
        int ok = 1, ans = 0, done = 0;
        for(int i=62;i>=0;i--) {
            int a = ((n >> i) & 1);
            int b = ((x >> i) & 1);
            // dbg(i, done, b);
            if(done && b) {
                ok = 0;
                break;
            }
            if(a == b) {
                if(a && !done) ans += (1ll << i);
                continue;
            }
            if(!a && b) {
                ok = 0;
                break;
            }
            if(a && !b && !done) {
                for(int j=i+1;j<=63;j++) {
                    if(((n >> j) & 1) == 0) {
                        ans += (1ll << j);
                        break;
                    } else {
                        ok = 0;
                        break;
                    }
                }
                done = 1;
                dbg(i, ans);
            }
        }
        if(!ok) cout << -1 << endl;
        else cout << ans << endl;
    }
}