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
        vector<int> x(n), y(n);
        for(int i=0;i<n;i++) {
            cin >> x[i];
        }
        for(int i=0;i<n;i++) {
            cin >> y[i];
        }
        multiset<vector<int>> good, bad;
        for(int i=0;i<n;i++) {
            if(x[i] <= y[i]) good.insert({y[i] - x[i], x[i], y[i]});
            else bad.insert({x[i] - y[i], x[i], y[i]});
        }
        // dbg(good);
        // dbg(bad);
        int ans = 0;
        for(auto i : bad) {
            int req = i[0];
            auto it = good.lower_bound({req, -1, -1});
            if(it == good.end()) break;
            ans++;
            good.erase(it);
        }
        ans += good.size() / 2;
        cout << ans << endl;
    }
}