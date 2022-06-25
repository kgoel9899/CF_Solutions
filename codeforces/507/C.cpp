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
        int h, n;
        cin >> h >> n;
        int ans = 0;
        int ch = 0; // 0 = L, 1 = R
        // cout << (1ll << 35) << endl;
        while(h) {
            int left_leaves = (1ll << (h - 1));
            dbg(h, n, left_leaves);
            if(n <= left_leaves) {
                dbg("here", ch, n);
                // it is in the left part
                ans++;
                if(ch == 1) {
                    // visit the complete right part
                    ans += (1ll << h) - 1;
                    // ch = 0;
                } else ch = 1;
            } else {
                // it is in the right part
                dbg("here2", ch, n);
                ans++;
                n -= left_leaves;
                dbg(ch);
                if(ch == 0) {
                    // visit the complete left part
                    // ans++;
                    ans += (1ll << h) - 1;
                    // n -= left_leaves;
                    // ch = 1;
                } else ch = 0;
            }
            h--;
            dbg(ans);
            // ch ^= 1;
        }
        cout << ans << endl;
    }
}