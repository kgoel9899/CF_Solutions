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
        string s;
        cin >> s;
        int l = -1, r = n;
        for(int i=0;i<n;i++) {
            if(s[i] == '1') {
                if(l == -1) {
                    l = i;
                    r = i;
                } else r = i;
            }
        }
        dbg(l, r);
        if(l == -1) {
            cout << 0 << endl;
            continue;
        }
        int done = 0;
        if(n - 1 - r <= k) {
            k -= n - 1 - r;
            swap(s[r], s[n - 1]);
            done = 1;
        }
        dbg(k);
        if(l <= k) {
            if(done && l == r) {
                
            } else {
                k -= l;
                swap(s[0], s[l]);
            }
        }
        dbg(s);
        int ans = 0;
        for(int i=1;i<n;i++) {
            ans += stoi(s.substr(i - 1, 2));
        }
        cout << ans << endl;
    }
}