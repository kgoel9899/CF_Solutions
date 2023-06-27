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
        vector<int> z(n);
        for(int i=1,l=0,r=0;i<n;i++) {
            if(i <= r) z[i] = min(r - i + 1, z[i - l]);
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                ++z[i];
            }
            if(i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        dbg(z);
        vector<int> pi(n);
        for(int i=1;i<n;i++) {
            int j = pi[i - 1];
            while(j > 0 && s[i] != s[j]) {
                j = pi[j-1];
            }
            if(s[i] == s[j]) j++;
            pi[i] = j;
        }
        dbg(pi);
        vector<int> ct(n + 1);
        for(int i=0;i<n;i++) {
            ct[pi[i]]++;
        }
        for(int i=n-1;i>0;i--) {
            ct[pi[i - 1]] += ct[i];
        }
        for(int i=0;i<=n;i++) {
            ct[i]++;
        }
        dbg(ct);
        vector<vector<int>> ans;
        for(int i=n-1;i>=1;i--) {
            if(z[i] == n - i) {
                // pefix/suffix of length z[i]
                ans.push_back({z[i], ct[z[i]]});
            }
        }
        ans.push_back({n, 1});
        sort(all(ans));
        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i[0] << " " << i[1] << endl;
        }
    }
} 