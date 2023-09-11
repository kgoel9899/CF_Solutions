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
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        a--;
        b--;
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i].first >> v[i].second;
        }
        int x = INF, y = INF;
        if(a < k) x = 0;
        if(b < k) y = 0;
        // dbg(b, k);
        for(int i=0;i<k;i++) {
            // dbg(i);
            if(a >= k) x = min(x, abs(v[i].first - v[a].first) + abs(v[i].second - v[a].second));
            if(b >= k) y = min(y, abs(v[i].first - v[b].first) + abs(v[i].second - v[b].second));
            // dbg(i, y);
        }
        cout << min(x + y, abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second)) << endl;
    }
}