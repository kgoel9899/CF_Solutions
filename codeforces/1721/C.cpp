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
        vector<int> ans1(n), ans2(n);
        int l = 0, r = 0;
        for(int i=0;i<n-1;i++) {
            if(b[i] >= a[i + 1]) {
                // same group
                r = i + 1;
            } else {
                for(int j=l;j<=r;j++) {
                    int lb = lower_bound(b.begin() + l, b.begin() + r + 1, a[j]) - b.begin();
                    ans1[j] = b[lb] - a[j];
                    ans2[j] = b[r] - a[j];
                }
                l = i + 1;
                r = i + 1;
            }
        }
        for(int j=l;j<=r;j++) {
            int lb = lower_bound(b.begin() + l, b.begin() + r + 1, a[j]) - b.begin();
            ans1[j] = b[lb] - a[j];
            ans2[j] = b[r] - a[j];
        }
        for(auto i : ans1) {
            cout << i << " ";
        }
        cout << endl;
        for(auto i : ans2) {
            cout << i << " ";
        }
        cout << endl;
    }
}