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

// a b c d e f g
// 1 2 3 1 2

// a b c d
// 2 1
bool solve(int k, int n, int c, int d, vector<int>& v) {
    int ans = 0;
    for(int i=0;i<d;i++) {
        if(i % (k + 1) < n) ans += v[i % (k + 1)];
    }
    return ans >= c;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        sort(all(v), greater<int>());
        // dbg(v);
        int beg = 0, end = 1e18;
        int ans = -1;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(solve(mid, n, c, d, v)) {
                ans = mid;
                beg = mid + 1;
            } else end = mid - 1;
        }
        if(ans == 1e18) cout << "Infinity" << endl;
        else if(ans == -1) cout << "Impossible" << endl;
        else cout << ans << endl;
    }
}