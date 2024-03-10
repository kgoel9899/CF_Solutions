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
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        map<int, map<int, int>> m; // {len, {sum, ct}}
        for(auto& i : v) {
            int s = 0;
            for(auto& j : i) {
                s += (j - '0');
            }
            m[i.size()][s]++;
        }
        dbg(m);
        int ans = 0;
        for(auto& i : v) {
            int len = i.size();
            for(int j=1;j<=len;j++) {
                if((j + len) % 2) continue;
                int mid = (j + len) / 2;
                int sm = 0, tot = 0;
                for(int k=0;k<len;k++) {
                    if(k < mid) sm += i[k] - '0';
                    tot += i[k] - '0';
                }
                int search = 2 * sm - tot;
                ans += m[j][search];
            }
        }
        dbg(ans);
        m.clear();
        for(auto& i : v) {
            reverse(all(i));
        }
        for(auto& i : v) {
            int s = 0;
            for(auto& j : i) {
                s += (j - '0');
            }
            m[i.size()][s]++;
        }
        dbg(m);
        for(auto& i : v) {
            int len = i.size();
            for(int j=1;j<len;j++) {
                if((j + len) % 2) continue;
                int mid = (j + len) / 2;
                dbg(i, len, j, mid);
                int sm = 0, tot = 0;
                for(int k=0;k<len;k++) {
                    if(k < mid) sm += i[k] - '0';
                    tot += i[k] - '0';
                }
                dbg(sm, tot);
                int search = 2 * sm - tot;
                ans += m[j][search];
            }
        }
        cout << ans << endl;
    }
}