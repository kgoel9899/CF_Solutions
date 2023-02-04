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
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> p(n);
        map<int, int> mp;
        for(int i=0;i<n;i++) {
            cin >> p[i];
            mp[p[i]] = i;
        }
        vector<int> a(m);
        for(int i=0;i<m;i++) {
            cin >> a[i];
        }
        int ans = INF;
        for(int i=1;i<m;i++) {
            int x = a[i - 1], y = a[i];
            int pos1 = mp[x], pos2 = mp[y];
            if(pos1 > pos2) {
                ans = 0;
                break;
            }
            int dist = pos2 - pos1;
            if(dist > d) {
                ans = 0;
                break;
            }
            if(d >= n - 1) {
                ans = min(ans, dist);
                continue;
            }
            ans = min(ans, dist);
            if(n - 1 - pos2 + dist > d) {
                ans = min(ans, d - dist + 1);
                continue;
            }
            dbg("here");
            dist += n - 1 - pos2;
            int curr = n - 1 - pos2;
            ans = min(ans, curr + d - dist + 1);
        }
        cout << ans << endl;
    }
}