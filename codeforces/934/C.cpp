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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        // find LIS
        vector<int> dp1(n, 1);
        for(int i=1;i<n;i++) {
            for(int j=i-1;j>=0;j--) {
                if(v[j] <= v[i]) dp1[i] = max(dp1[i], 1 + dp1[j]);
            }
        }
        dbg(dp1);
        reverse(all(v));
        dbg(v);
        // find LDS in reversed input (this basically means we are finding the LIS from ith index to n of original input)
        vector<int> dp2(n, 1);
        for(int i=1;i<n;i++) {
            for(int j=i-1;j>=0;j--) {
                if(v[j] >= v[i]) dp2[i] = max(dp2[i], 1 + dp2[j]);
            }
        }
        dbg(dp2);
        int ans = 0;
        for(int i=0;i<n-1;i++) {
            ans = max(ans, dp1[i] + dp2[n - 2 - i]);
        }
        ans = max(ans, dp1[n - 1]);
        cout << ans << endl;
    }
}