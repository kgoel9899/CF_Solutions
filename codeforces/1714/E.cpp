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
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int bad = 0, ok = 0, five = 0, zero = 0;
        map<int, int> m;
        for(int i=0;i<n;i++) {
            if(v[i] % 10 == 5) {
                bad = 1;
                five = 1;
            }
            else if(v[i] % 10 == 0) {
                bad = 1;
                zero = 1;
            }
            else {
                ok = 1;
                while(v[i] % 10 != 2) {
                    v[i] += v[i] % 10;
                }
            }
            m[v[i]]++;
        }
        if(ok && bad) {
            cout << "No" << endl;
            continue;
        }
        sort(all(v));
        // dbg(v);
        if(five && zero) {
            assert(m.size() >= 2);
            if(m.size() >= 3) cout << "No" << endl;
            else {
                int x = -1, y = -1;
                for(auto i : m) {
                    if(x == -1) x = i.first;
                    else y = i.first;
                }
                if(x % 10 == 0 || x + 5 != y) cout << "No" << endl;
                else cout << "Yes" << endl;
            }
        } else if(five || zero) {
            if(m.size() == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            int no = 0;
            for(int i=1;i<n;i++) {
                int d = v[i] - v[i - 1];
                if(d % 20 != 0) no = 1;
            }
            if(no) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
}