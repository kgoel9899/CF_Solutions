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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        multiset<int> s;
        int ans = 0;
        for(auto i : v) {
            ans += i / k;
            s.insert(i % k);
        }
        while(s.size()) {
            int curr = *s.begin();
            s.erase(s.begin());
            int left = k - curr;
            auto it = s.lower_bound(left);
            if(it == s.end()) continue;
            ans += (*it + curr) / k;
            s.erase(it);
        }
        cout << ans << endl;
    }
}

// 0, 2, 1, 1, 1, 2

// 2 + 7 = 9 -> 3
// 4 + 8 = 12 -> 4
// 3 + 1 = 4 -> 1