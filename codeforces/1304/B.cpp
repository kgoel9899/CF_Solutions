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

bool pal(string& s) {
    int a = 0, b = (int)s.size() - 1;
    while(a < b) {
        if(s[a] != s[b]) return false;
        a++;
        b--;
    }
    return true;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        multiset<string> s;
        int ans = 0;
        string pref = "", suff = "", mid = "";
        int done = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            string temp = v[i];
            reverse(all(temp));
            if(s.find(temp) != s.end()) {
                ans += 2 * v[i].size();
                pref += v[i];
                suff = temp + suff;
                s.erase(s.find(temp));
            } else {
                if(!done && pal(v[i])) {
                    done = 1;
                    mid = v[i];
                    ans += v[i].size();
                } else s.insert(v[i]);
            }
        }
        cout << ans << endl;
        cout << pref + mid + suff << endl;
    }
}