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
        string s;
        cin >> s;
        map<int, vector<int>> m;
        vector<int> ans(n);
        int ct = 1;
        for(int i=0;i<n;i++) {
            if(s[i] == '0') {
                if(m[1].size()) {
                    ans[i] = m[1].back();
                    m[1].pop_back();
                    m[0].push_back(ans[i]);
                } else {
                    ans[i] = ct;
                    m[0].push_back(ct);
                    ct++;
                }
            } else {
                if(m[0].size()) {
                    ans[i] = m[0].back();
                    m[0].pop_back();
                    m[1].push_back(ans[i]);
                } else {
                    ans[i] = ct;
                    m[1].push_back(ct);
                    ct++;
                }
            }
        }
        int mx = 0;
        for(auto i : ans) {
            mx = max(mx, i);
        }
        cout << mx << endl;
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}