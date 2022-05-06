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
    int t = 1;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int mx = 0;
        char low = 'Z', high = 'Z';
        for(int i=0;i<n;i++) {
            int diff = s[i] - 'a';
            if(diff > mx) {
                if((diff - mx) <= k) {
                    k -= (diff - mx);
                    s[i] = 'a';
                    mx = diff;
                } else {
                    if(low == 'Z' && high == 'Z') {
                        high = s[i];
                        low = s[i] - k;
                        // dbg(high, low);
                        s[i] = low;
                    } else {
                        assert(low != 'Z');
                        assert(high != 'Z');
                        if(s[i] >= low && s[i] <= high) s[i] = low;
                    }
                    k = 0;
                }
            } else s[i] = 'a';
        }
        // dbg(k);
        cout << s << endl;
    }
}