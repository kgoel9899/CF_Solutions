#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define endl "\n"
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

// find sequence 'p' by asking query '1'
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int m, n;
        cin >> m >> n;
        cout << 1 << endl;
        int inp;
        cin >> inp;
        if(inp == 0) break;
        vector<int> p(n);
        if(inp == 1) p[0] = 1;
        for(int i=1;i<n;i++) {
            cout << 1 << endl;
            cin >> inp;
            if(inp == 1) p[i] = 1;
        }
        int beg = 2, end = m;
        int ind = 0;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            cout << mid << endl;
            cin >> inp;
            if(inp == 0) break;
            else if(inp == -1) {
                if(p[ind] == 1) end = mid - 1;
                else beg = mid + 1;
            } else {
                if(p[ind] == 1) beg = mid + 1;
                else end = mid - 1;
            }
            ind++;
            ind %= n;
        }
    }
}