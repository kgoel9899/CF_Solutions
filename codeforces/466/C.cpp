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
        int n;
        cin >> n;
        vector<int> v(n);
        int s = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            s += v[i];
        }
        if(s % 3 != 0) {
            cout << 0 << endl;
            continue;
        }
        vector<int> pref(n); // sum from 0...i
        pref[0] = v[0];
        for(int i=1;i<n;i++) {
            pref[i] = pref[i - 1] + v[i];
        }
        vector<int> suff(n); // sum from i...n-1
        suff[n - 1] = v[n - 1];
        for(int i=n-2;i>=0;i--) {
            suff[i] = suff[i + 1] + v[i];
        }
        vector<int> cnt(n); // cnt from i...n-1;
        if(suff[n - 1] == s / 3) cnt[n - 1] = 1;
        for(int i=n-2;i>=0;i--) {
            cnt[i] = cnt[i + 1];
            if(suff[i] == s / 3) cnt[i]++;
        }
        dbg(pref);
        dbg(suff);
        dbg(cnt);
        dbg(s);
        int ans = 0;
        for(int i=0;i<n-2;i++) {
            if(pref[i] != s / 3) continue;
            ans += cnt[i + 2];
        }
        cout << ans << endl;
    }
}