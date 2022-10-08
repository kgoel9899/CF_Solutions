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
        string s;
        cin >> s;
        int n = s.size();
        vector<int> z(n);
        for(int i=1,l=0,r=0;i<n;i++) {
            if(i <= r) z[i] = min(r - i + 1, z[i - l]);
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                ++z[i];
            }
            if(i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        int ans = 0, mx_z = z[1];
        for(int i=2;i<n;i++) {
            // i..n-1 is valid or not
            if(z[i] == 0) continue;
            int len = n - i;
            int mx_z_till_now = mx_z;
            mx_z = max(mx_z, z[i]);
            if(z[i] != len) continue;
            if(mx_z_till_now >= len) {
                ans = len;
                break;
            }
        }
        if(ans == 0) cout << "Just a legend" << endl;
        else cout << s.substr(0, ans) << endl;
    }
}