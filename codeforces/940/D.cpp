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
        string s;
        cin >> s;
        int l = -1e9, r = 1e9;
        for(int i=4;i<n;i++) {
            int z = 0, o = 0;
            for(int j=i-1;j>=i-4;j--) {
                if(s[j] == '1') o++;
                else z++;
            }
            if(z && o) continue;
            int mx = max({v[i], v[i - 1], v[i - 2], v[i - 3], v[i - 4]});
            int mn = min({v[i], v[i - 1], v[i - 2], v[i - 3], v[i - 4]});
            if(s[i] == '1') {
                if(z) l = max(l, mx + 1);
            } else {
                if(o) r = min(r, mn - 1);
            }
        }
        assert(l <= r);
        cout << l << " " << r << endl;
    }
}