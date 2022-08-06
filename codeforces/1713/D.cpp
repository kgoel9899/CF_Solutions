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

int solve(int a, int b, int c, int d) {
    cout << "? " << a << " " << c << endl;
    int inp;
    cin >> inp;
    if(inp == 1) {
        cout << "? " << a << " " << d << endl;
        cin >> inp;
        if(inp == 1) return a;
        else return d;
    } else if(inp == 2) {
        cout << "? " << c << " " << b << endl;
        cin >> inp;
        if(inp == 1) return c;
        else return b;
    } else {
        cout << "? " << b << " " << d << endl;
        cin >> inp;
        if(inp == 1) return b;
        else return d;
    }
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v((1 << n));
        for(int i=0;i<(1<<n);i++) {
            v[i] = i + 1;
        }
        vector<int> win;
        while(v.size() >= 4) {
            assert(v.size() % 4 == 0);
            for(int i=0;i<v.size();i+=4) {
                win.push_back(solve(v[i], v[i + 1], v[i + 2], v[i + 3]));
            }
            v = win;
            win.clear();
        }
        if(v.size() == 1) cout << "! " << v[0] << endl;
        else {
            assert(v.size() == 2);
            cout << "? " << v[0] << " " << v[1] << endl;
            int inp;
            cin >> inp;
            if(inp == 1) cout << "! " << v[0] << endl;
            else cout << "! " << v[1] << endl;
        }
    }
}
// 0 1 0 2 0 1 0 3