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
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        vector<int> b(m);
        for(int i=0;i<m;i++) {
            cin >> b[i];
        }
        sort(all(a));
        sort(all(b));
        int last = -1;
        int x = 0, y = INF;
        for(int i=0;i<n;i++) {
            if(a[i] == last) continue;
            int sa = i * 2 + (n - i) * 3;
            int ind = upper_bound(all(b), a[i] - 1) - b.begin();
            int sb = ind * 2 + (m - ind) * 3;
            if(sa - sb > x - y) {
                x = sa;
                y = sb;
            } else if(sa - sb == x - y) {
                if(sa > x) {
                    x = sa;
                    y = sb;
                }
            }
        }
        int sa = 2 * n;
        int sb = 2 * m;
        if(sa - sb > x - y) {
            x = sa;
            y = sb;
        } else if(sa - sb == x - y) {
            if(sa > x) {
                x = sa;
                y = sb;
            }
        }
        cout << x << ":" << y << endl;
    }
}