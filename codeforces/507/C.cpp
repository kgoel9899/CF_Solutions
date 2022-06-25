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
        int ch = 0; // 0 = L, 1 = R .. direction to move w.r.t. to the current node
        while(h) {
            int left_leaves = (1ll << (h - 1));
            if(n <= left_leaves) {
                // it is in the left part
                ans++; // for the current node
                if(ch == 1) {
                    // visit the complete right part
                    ans += (1ll << h) - 1;
                }
                // if ch == 0, then we would have moved left so the next direction is right -> ch = 1;
                // if ch == 1, then after including the complete right part, we would have moved left of the current node
                // so the next direction is right -> ch = 1;
                // both the cases -> ch = 1;
                ch = 1;
            } else {
                // it is in the right part
                ans++; // for the current node
                n -= left_leaves; // because it is in the right part, subtract the leaves in the left part to maintain consistency
                if(ch == 0) {
                    // visit the complete left part
                    ans += (1ll << h) - 1;
                }
                // if ch == 1, then we would have moved right so the next direction is left -> ch = 0;
                // if ch == 0, then after including the complete left part, we would have moved right of the current node
                // so the next direction is left -> ch = 0;
                // both the cases -> ch = 0;
                ch = 0;
            }
            h--;
        }
        cout << ans << endl;
    }
}