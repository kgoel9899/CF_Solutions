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
        vector<int> v(n);
        map<int,int> m;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            m[v[i]]++;
        }            
        if(m.size() == 1) {
            cout << 0 << endl;
            continue;
        }
        if(m.begin()->first == 1) {
            cout << -1 << endl;
            continue;
        }
        vector<pair<int, int>> ans;
        while(m.size() > 1) {
            vector<vector<int>> curr;
            for(int i=0;i<n;i++) {
                curr.push_back({v[i], i});
            }
            sort(curr.begin(), curr.end());
            for(int i=0;i<n;i++){
                if(curr[0][0] == curr[i][0]) continue;
                ans.push_back({curr[i][1], curr[0][1]});
                v[curr[i][1]] = (v[curr[i][1]] + v[curr[0][1]] - 1) / v[curr[0][1]];
            }
            m.clear();
            for(auto& i : v) {
                m[i]++;
            }
        }
        cout << ans.size() << endl;
        for(auto& i : ans) {
            cout << i.first + 1 << " " << i.second + 1 << endl;
        }
    }
}