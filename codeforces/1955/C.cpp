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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int l = 0, r = n - 1;
        int ans = 0;
        while(l <= r && k > 1) {
            if(l == r) {
                k -= v[l];
                if(k >= 0) ans++;
                l++;
                break;
            }
            int mn = min({v[l], v[r], k / 2});
            dbg(l, r, v[l], v[r], mn, k);
            k -= 2 * mn;
            v[l] -= mn;
            if(v[l] == 0) {
                ans++;
                l++;
            }
            v[r] -= mn;
            if(v[r] == 0) {
                ans++;
                r--;
            }
            dbg(l, r, k, ans);
        }
        if(k && l <= r && v[l] == 1) ans++;
        cout << ans << endl;
    }
}