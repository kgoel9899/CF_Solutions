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
        int n, s;
        cin >> n >> s;
        int curr = 0;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
            curr += v[i];
        }
        if(curr == s) {
            cout << 0 << endl;
            continue;
        }
        if(curr < s) {
            cout << -1 << endl;
            continue;
        }
        int req = curr - s;
        vector<int> pref(n), suff(n);
        pref[0] = v[0];
        suff[n - 1] = v[n - 1];
        for(int i=1;i<n;i++) {
            pref[i] = pref[i - 1] + v[i];
        }
        for(int i=n-2;i>=0;i--) {
            suff[i] = suff[i + 1] + v[i];
        }
        reverse(all(suff));
        dbg(pref);
        dbg(suff);
        int ans = INF;
        for(int l=0;l<=req;l++) {
            int r = req - l;
            int ind1 = lower_bound(all(pref), l) - pref.begin();
            int ind2 = lower_bound(all(suff), r) - suff.begin();
            if(l != 0) ind1++;
            if(r != 0) ind2++;
            dbg(l, r, ind1, ind2);
            ans = min(ans, ind1 + ind2);
        }
        cout << ans << endl;
    }
}