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
        string a, b;
        cin >> a >> b;
        int ok = 1;
        for(int i=0;i<n;i++) {
            if(abs(a[i] - b[i]) != 1) ok = 0;
        }
        if(a == b) ok = 1;
        if(!ok) {
            cout << "NO" << endl;
            continue;
        }
        vector<pair<int, int>> ans;
        cout << "YES" << endl;
        if(a != b) ans.push_back({1, n});
        a = b;
        vector<int> tot(n);
        for(int i=0;i<n;i++) {
            if(a[i] == '0') continue;
            if(i == 0) {
                ans.push_back({1, n});
                ans.push_back({2, n});
            }
            else {
                tot[i]++;
                tot[i - 1]++;
            }
        }
        for(int i=0;i<n;i++) {
            if(tot[i] % 2) ans.push_back({1, i + 1});
        }
        cout << ans.size() << endl;
        for(auto& i : ans) {
            cout << i.first << " " << i.second << endl;
        }
    }
}