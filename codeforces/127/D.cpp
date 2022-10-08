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
        if(pi[n - 1] == 0) {
            cout << "Just a legend" << endl;
            continue;
        }
        int ok = 0;
        for(int i=1;i<n-1;i++) {
            if(pi[i] == pi[n - 1]) {
                ok = 1;
                break;
            }
        }
        if(ok) cout << s.substr(0, pi[n - 1]);
        else {
            if(pi[pi[n - 1] - 1] == 0) cout << "Just a legend" << endl;
            else cout << s.substr(0, pi[pi[n - 1] - 1]) << endl;
        }
    }
}