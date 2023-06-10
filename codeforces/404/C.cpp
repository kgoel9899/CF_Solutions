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

int n, k;
vector<int> d;
map<int, vector<int>> m;
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> k;
        d.clear();
        d.resize(n + 1);
        m.clear();
        for(int i=1;i<=n;i++) {
            cin >> d[i];
            m[d[i]].push_back(i);
        }
        dbg(m);
        if(m.begin()->first != 0 || m.begin()->second.size() > 1) {
            cout << -1 << endl;
            continue;
        }
        if(m.rbegin()->first != m.size() - 1) {
            cout << -1 << endl;
            continue;
        }
        vector<vector<int>> adj(n + 1);
        int root = m.begin()->second[0];
        m.erase(0);
        dbg(root, m);
        vector<pair<int, int>> ans;
        queue<int> q;
        q.push(root);
        int ok = 1;
        for(auto& i : m) {
            int sz = q.size(), ind = 0, tot = i.second.size();
            while(sz--) {
                auto f = q.front();
                q.pop();
                if(ind == tot) continue;
                int ct = 0;
                while(ct < (f == root ? k : k - 1) && ind < tot) {
                    ans.push_back({f, i.second[ind]});
                    q.push(i.second[ind]);
                    ct++;
                    ind++;
                }
            }
            if(ind < tot) {
                ok = 0;
                break;
            }
            dbg(ans);
        }
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        cout << ans.size() << endl;
        for(auto& i : ans) {
            cout << i.first << " " << i.second << endl;
        }
    }
}