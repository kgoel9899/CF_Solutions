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
    // cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> bad(26);
        string t;
        cin >> t;
        for(int i=0;i<26;i++) {
            if(t[i] == '0') bad[i] = 1;
        }
        int k;
        cin >> k;
        vector<int> ppow1(n), ppow2(n);
        ppow1[0] = ppow2[0] = 1;
        const int p1 = 29, p2 = 31;
        for(int i=1;i<n;i++) {
            ppow1[i] = (ppow1[i - 1] * p1) % MOD;
            ppow2[i] = (ppow2[i - 1] * p2) % MOD;
        }
        vector<int> hash1(n), hash2(n);
        hash1[0] = ((s[0] - 'a' + 1) * ppow1[0]) % MOD;
        hash2[0] = ((s[0] - 'a' + 1) * ppow2[0]) % MOD;
        for(int i=1;i<n;i++) {
            hash1[i] = (hash1[i - 1] + (s[i] - 'a' + 1) * ppow1[i]) % MOD;
            hash2[i] = (hash2[i - 1] + (s[i] - 'a' + 1) * ppow2[i]) % MOD;
        }
        set<pair<int, int>> ans;
        for(int i=0;i<n;i++) {
            int ct = 0;
            for(int j=i;j<n;j++) {
                if(bad[s[j] - 'a']) ct++;
                if(ct > k) break;
                int curr1 = (hash1[j] - (i ? hash1[i - 1] : 0) + MOD) % MOD;
                curr1 *= ppow1[n - 1 - i];
                curr1 %= MOD;
                int curr2 = (hash2[j] - (i ? hash2[i - 1] : 0) + MOD) % MOD;
                curr2 *= ppow2[n - 1 - i];
                curr2 %= MOD;
                ans.insert({curr1, curr2});
            }
        }
        cout << ans.size() << endl;
    }
}
