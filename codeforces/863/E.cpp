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

const int N = 12e5 + 5;
const int LOG = 20;
int sparse[N][LOG];
int query(int l, int r) {
    int len = r - l + 1;
    int lg = log2(len);
    return min(sparse[l][lg], sparse[r - (1 << lg) + 1][lg]);
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        memset(sparse, 0, sizeof sparse);
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        set<int> s;
        for(int i=0;i<n;i++) {
            cin >> v[i].first >> v[i].second;
            s.insert(v[i].first);
            s.insert(v[i].first - 1);
            s.insert(v[i].second);
        }
        dbg(s);
        int x = 1;
        map<int, int> m;
        for(auto i : s) {
            m[i] = x++;
        }
        for(int i=0;i<n;i++) {
            v[i].first = m[v[i].first];
            v[i].second = m[v[i].second];
        }
        dbg(v);
        dbg(x);
        vector<int> pref(x + 1);
        for(int i=0;i<n;i++) {
            pref[v[i].first]++;
            pref[v[i].second + 1]--;
        }
        dbg(pref);
        for(int i=1;i<=x;i++) {
            pref[i] += pref[i - 1];
            sparse[i][0] = pref[i];
        }
        dbg(pref);
        for(int j=1;j<LOG;j++) {
            for(int i=0;i+(1<<(j-1))<x;i++) {
                sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
            }
        }
        dbg(v);
        int ans = -1;
        for(int i=0;i<n;i++) {
            if(query(v[i].first, v[i].second) >= 2) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }
}
