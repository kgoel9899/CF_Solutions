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
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        for(int i=0;i<n;i++) {
            cin >> b[i];
        }
        vector<int> as = a;
        sort(all(as));
        vector<int> bs = b;
        sort(all(bs));
        vector<vector<int>> ans;
        int ok = 1;
        for(int i=0;i<n;i++) {
            if(a[i] == as[i] && b[i] == bs[i]) continue;
            for(int j=i+1;j<n;j++) {
                if(a[j] == as[i] && b[j] == bs[i]) {
                    ans.push_back({i, j});
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    break;
                }
            }
            if(a[i] == as[i] && b[i] == bs[i]) continue;
            ok = 0;
            break;
        }
        if(!ok) cout << -1 << endl;
        else {
            cout << ans.size() << endl;
            for(auto i : ans) {
                cout << i[0] + 1 << " " << i[1] + 1 << endl;
            }
        }
    }
}