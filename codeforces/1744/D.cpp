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
        vector<int> v(n);
        int odd = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            if(v[i] % 2 == 0) {
                v[i] /= 2;
                while(v[i] % 2 == 0) {
                    v[i] /= 2;
                    odd--;
                }
            } else odd++;
        }
        dbg(odd);
        // i want odd no. of 2s
        int ans = 0;
        int curr = n;
        vector<int> pw;
        while(curr >= 2) {
            int p = 0;
            int temp = curr;
            while(temp % 2 == 0) {
                p++;
                temp /= 2;
            }
            // dbg(curr, p);
            if(p) pw.push_back(p);
            // if(p) {
            //     ans++;
            //     odd -= p;
            // }
            // dbg(odd);
            curr--;
        }
        sort(all(pw), greater<int>());
        dbg(pw);
        if(odd > 0) {
            for(auto i : pw) {
                odd -= i;
                ans++;
                if(odd <= 0) break;
            }
        }
        // dbg(odd);
        if(odd > 0) cout << -1 << endl;
        else cout << ans << endl;
    }
}