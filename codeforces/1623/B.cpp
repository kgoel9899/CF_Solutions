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
        return;
    }
    for(int i=l;i<=r;i++) {
        if(i == l) {
            if(s.find({l + 1, r}) != s.end()) {
                ans.push_back({l, r, l});
                dfs(l + 1, r);
            }
        } else if(i == r) {
            if(s.find({l, r - 1}) != s.end()) {
                ans.push_back({l, r, r});
                dfs(l, r - 1);
            }
        } else {
            if((s.find({l, i - 1}) != s.end()) && (s.find({i + 1, r}) != s.end())) {
                ans.push_back({l, r, i});
                dfs(l, i - 1);
                dfs(i + 1, r);
            }
        }
    }
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
        ans.clear();
        dfs(1, n);
        for(auto i : ans) {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }
    }
}