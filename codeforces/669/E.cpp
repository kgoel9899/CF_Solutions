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

const int N = 1e5 + 5;
int n;
map<int, map<int, int>> m;
void update(int ind, int num, int val) {
    while(ind < N) {
        m[num][ind] += val;
        ind += (ind & (-ind));
    }
}
int query(int ind, int num) {
    int ans = 0;
    while(ind > 0) {
        ans += m[num][ind];
        ind -= (ind & (-ind));
    }
    return ans;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    vector<vector<int>> v;
    map<int, int> mp;
    while(tt--) {
        cin >> n;
        while(n--) {
            int a, t, x;
            cin >> a >> t >> x;
            v.push_back({a, t, x});
            mp[t];
        }
        n = v.size();
        int rank = 1;
        for(auto i : mp) {
            mp[i.first] = rank++;
        }
        for(int i=0;i<n;i++) {
            v[i][1] = mp[v[i][1]];
        }
        for(int i=0;i<n;i++) {
            int a = v[i][0];
            int t = v[i][1];
            int x = v[i][2];
            if(a == 1) update(t, x, 1);
            else if(a == 2) update(t, x, -1);
            else cout << query(t, x) << endl;
        }
    }
}