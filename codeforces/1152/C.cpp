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

// editorial
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int a, b;
        cin >> a >> b;
        int diff = abs(a - b);
        vector<int> v;
        for(int i=1;i*i<=diff;i++) {
            if(diff % i == 0) {
                v.push_back(i);
                if(i != diff / i) v.push_back(diff / i);
            }
        }
        dbg(v);
        int ans = INF, k = 0;
        for(auto i : v) {
            if(a % i != b % i) continue; // (a + k) % i = (b + k) % i = 0a
            int temp = i - a % i;
            if(temp == i) temp = 0;
            int na = a + temp, nb = b + temp;
            int curr = (na * nb) / __gcd(na, nb);
            if(curr < ans) {
                ans = curr;
                k = temp;
            }
        }
        cout << k << endl;
    }
}