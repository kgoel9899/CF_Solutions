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
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> ans(n);
        ans[0] = a;
        ans[n / 2] = b;
        set<int> s;
        for(int i=1;i<=n;i++) {
            if(i == a || i == b) continue;
            s.insert(i);
        }
        int ok = 1;
        for(int i=1;i<n/2;i++) {
            int x = *s.rbegin();
            s.erase(*s.rbegin());
            if(x < a) {
                ok = 0;
                break;
            }
            ans[i] = x;
        }
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        for(int i=n/2+1;i<n;i++) {
            int x = *s.rbegin();
            s.erase(*s.rbegin());
            if(x > b) {
                ok = 0;
                break;
            }
            ans[i] = x;
        }
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        for(auto& i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}