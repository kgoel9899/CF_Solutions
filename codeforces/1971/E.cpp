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
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(k), b(k);
        for(int i=0;i<k;i++) {
            cin >> a[i];
        }
        for(int i=0;i<k;i++) {
            cin >> b[i];
        }
        while(q--) {
            int d;
            cin >> d;
            if(d < a[0]) {
                cout << d * b[0] / a[0] << " ";
                continue;
            }
            if(d == a.back()) {
                cout << b.back() << " ";
                continue;
            }
            int ind = upper_bound(all(a), d) - a.begin();
            ind--;
            cout << b[ind] + (d - a[ind]) * (b[ind + 1] - b[ind]) / (a[ind + 1] - a[ind]) << " ";
        }
        cout << endl;
    }
}