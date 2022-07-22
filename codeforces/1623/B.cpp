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

int n;
set<pair<int, int>> s;
vector<vector<int>> ans;
void dfs(int l, int r) {
    if(l > r) return;
    if(l == r) {
        ans.push_back({l, r, l});
        // s.erase({l, r});
        return;
    }
    int ok = 0;
    for(int i=l;i<=r;i++) {
        int ok1 = 1, ok2 = 1;
        if(l <= i - 1 && s.count({l, i - 1}) == 0) ok1 = 0;
        if(i + 1 <= r && s.count({i + 1, r}) == 0) ok2 = 0;
        if(ok1 && ok2) {
            ans.push_back({l, r, i});
            // s.erase({l, i - 1});
            // s.erase({i + 1, r});
            ok = 1;
            dfs(l, i - 1);
            dfs(i + 1, r);
            break;
        }
    }
    // dbg(l, r, ok);
    assert(ok);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n;
        s.clear();
        for(int i=0;i<n;i++) {
            int a, b;
            cin >> a >> b;
            s.insert({a, b});
        }
        dbg(s);
        ans.clear();
        dfs(1, n);
        for(auto i : ans) {
            for(auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
}