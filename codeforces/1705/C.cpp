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
        int n, c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        s = '#' + s;
        vector<pair<int, int>> v;
        while(c--) {
            int l, r;
            cin >> l >> r;
            v.push_back({l, r});
        }
        vector<int> pref;
        pref.push_back(n);
        for(int i=0;i<v.size();i++) {
            pref.push_back(pref.back() + v[i].second - v[i].first + 1);
        }
        // dbg(pref);
        while(q--) {
            int k;
            cin >> k;
            if(k <= n) {
                cout << s[k] << endl;
                continue;
            }
            int tot = n;
            int i = 0;
            for(;i<v.size();i++) {
                int len = v[i].second - v[i].first + 1;
                tot += len;
                if(tot >= k) {
                    break;
                }
                // tot += len;
            }
            assert(i < v.size());
            // dbg(i, tot);
            int prev = v[i].second - (tot - k);
            // dbg(prev);
            tot -= v[i].second - v[i].first + 1;
            // dbg(tot);
            i--;
            // dbg(i);
            while(prev > n) {
                assert(i >= 0);
                if(tot - (v[i].second - v[i].first) > prev) {
                    tot -= v[i].second - v[i].first + 1;
                    i--;
                    continue;
                }
                prev = v[i].second - (tot - prev);
                tot -= v[i].second - v[i].first + 1;
                // dbg(prev, tot);
                i--;
                // break;
            }
            // dbg(prev);
            assert(prev >= 1 && prev <= n);
            cout << s[prev] << endl;
        }
    }
}

// mark mar kmar

// m m mm mmm


// mark
// mark ark
// mark ark kark
// mark mar kmar


// mark

// mark ar
// mark ar markar


// mark
// mark k k