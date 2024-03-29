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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> pref(n);
        pref[0] = (s[0] == '1');
        for(int i=1;i<n;i++) {
            pref[i] = pref[i - 1] + (s[i] == '1');
        }
        int ans;
        double mn = 2 * n;
        if(pref[n - 1] >= (n + 1) / 2) {
            ans = 0;
            mn = n / 2.0;
        } else if(n - pref[n - 1] >= (n + 1) / 2) {
            ans = n;
            mn = n / 2.0;
        }
        for(int i=1;i<n;i++) {
            // place before ith house
            int ltot = i;
            int l = ltot - pref[i - 1];
            int rtot = n - i;
            int r = pref[n - 1] - pref[i - 1];
            if(l >= (ltot + 1) / 2 && r >= (rtot + 1) / 2) {
                double dist = abs(n / 2.0 - i);
                if(dist < mn) {
                    mn = dist;
                    ans = i;
                }
            }
        }
        cout << ans << endl;
    }
}