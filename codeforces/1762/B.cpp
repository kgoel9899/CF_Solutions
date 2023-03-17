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
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(all(v));
        int prev = v[0].first;
        vector<pair<int, int>> ans;
        for(int i=1;i<n;i++) {
            if(v[i].first == prev) continue;
            if(v[i].first < prev) {
                ans.push_back({v[i].second + 1, prev - v[i].first});
                continue;
            }
            if(v[i].first % prev == 0) {
                prev = v[i].first;
                continue;
            }
            int div = v[i].first / prev;
            int temp = prev * (div + 1);
            prev = temp;
            ans.push_back({v[i].second + 1, temp - v[i].first});
        }
        cout << ans.size() << endl;
        for(auto& i : ans) {
            cout << i.first << " " << i.second << endl;
        }
    }
}