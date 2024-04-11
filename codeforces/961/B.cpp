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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        vector<int> t(n);
        for(int i=0;i<n;i++) {
            cin >> t[i];
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(t[i]) ans += a[i];
        }
        vector<int> pref(n);
        if(!t[0]) pref[0] = a[0];
        for(int i=1;i<n;i++) {
            pref[i] = pref[i - 1];
            if(!t[i]) pref[i] += a[i];
        }
        int mx = pref[k - 1];
        for(int i=k;i<n;i++) {
            mx = max(mx, pref[i] - pref[i - k]);
        }
        cout << ans + mx << endl;
    }
}