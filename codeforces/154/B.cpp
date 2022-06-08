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
        int n, m;
        cin >> n >> m;
        vector<int> vis(n + 1);
        vector<vector<int>> pr(n + 1);
        vector<int> spf(n + 1);
        for(int i=0;i<=n;i++) {
            spf[i] = i;
        }
        for(int i=2;i*i<=n;i++) {
            if(spf[i] == i) {
                for(int j=i*i;j<=n;j+=i) {
                    spf[j] = min(spf[j], i);
                }
            }
        }
        for(int i=2;i<=n;i++) {
            int temp = i;
            while(temp > 1) {
                int ct = 0, div = spf[temp];
                while(temp % div == 0) {
                    ct++;
                    temp /= div;
                }
                if(ct) pr[i].push_back(div);
            }
        }
        dbg(pr);
        multiset<pair<int, int>> s;
        while(m--) {
            char c;
            int val;
            cin >> c >> val;
            if(c == '+') {
                if(vis[val]) {
                    cout << "Already on" << endl;
                    continue;
                }
                int ok = 1, conf = -1;
                for(auto i : pr[val]) {
                    auto it = s.lower_bound({i, -1});
                    if(it->first == i) {
                        ok = 0;
                        conf = it->second;
                        break;
                    }
                }
                if(ok) {
                    vis[val] = 1;
                    for(auto i : pr[val]) {
                        s.insert({i, val});
                    }
                    cout << "Success" << endl;
                } else {
                    assert(conf != -1);
                    cout << "Conflict with " << conf << endl;
                }
            } else {
                if(!vis[val]) {
                    cout << "Already off" << endl;
                    continue;
                }
                vis[val] = 0;
                cout << "Success" << endl;
                for(auto i : pr[val]) {
                    s.erase(s.find({i, val}));
                }
            }
        }
    }
}