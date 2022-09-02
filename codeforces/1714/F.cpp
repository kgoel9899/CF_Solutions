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
        int n, d12, d23, d31;
        cin >> n >> d12 >> d23 >> d31;
        if((d12 + d23 + d31) % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }
        vector<int> v = {d12, d23, d31};
        sort(all(v));
        if(v[2] == v[0] + v[1]) {
            // line
            if(n < v[2] + 1) {
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            int mid = -1;
            if(v[2] == d12) mid = 3;
            else if(v[2] == d23) mid = 1;
            else mid = 2;
            int curr, node = 4;
            if(mid == 1) {
                curr = 1;
                d12--;
                while(d12--) {
                    cout << curr << " " << node << endl;
                    curr = node;
                    node++;
                }
                cout << curr << " " << 2 << endl;
                d31--;
                curr = 1;
                while(d31--) {
                    cout << curr << " " << node << endl;
                    curr = node;
                    node++;
                }
                cout << curr << " " << 3 << endl;
            } else if(mid == 2) {
                curr = 2;
                d12--;
                while(d12--) {
                    cout << curr << " " << node << endl;
                    curr = node;
                    node++;
                }
                cout << curr << " " << 1 << endl;
                d23--;
                curr = 2;
                while(d23--) {
                    cout << curr << " " << node << endl;
                    curr = node;
                    node++;
                }
                cout << curr << " " << 3 << endl;
            } else {
                curr = 3;
                d31--;
                while(d31--) {
                    cout << curr << " " << node << endl;
                    curr = node;
                    node++;
                }
                cout << curr << " " << 1 << endl;
                d23--;
                curr = 3;
                while(d23--) {
                    cout << curr << " " << node << endl;
                    curr = node;
                    node++;
                }
                cout << curr << " " << 2 << endl;
            }
            while(node <= n) {
                cout << "1 " << node++ << endl;
            }
        } else {
            // star
            // d12 = x + y
            // d23 = y + z
            // d31 = z + x
            int a = d12 - d23 + d31;
            int b = d23 - d31 + d12;
            int c = d31 - d12 + d23;
            if(a % 2 || b % 2 || c % 2 || min({a, b, c}) < 0) {
                cout << "NO" << endl;
                continue;
            }
            int x = a / 2;
            int y = b / 2;
            int z = c / 2;
            if(n < x + y + z + 1) {
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            int curr = 1, node = 4;
            while(x--) {
                cout << curr << " " << node << endl;
                curr = node;
                node++;
            }
            int mid = curr;
            y--;
            while(y--) {
                cout << curr << " " << node << endl;
                curr = node;
                node++;
            }
            cout << curr << " " << 2 << endl;
            z--;
            curr = mid;
            while(z--) {
                cout << curr << " " << node << endl;
                curr = node;
                node++;
            }
            cout << curr << " " << 3 << endl;
            while(node <= n) {
                cout << "1 " << node++ << endl;
            }
        }
    }
}
// z = d31 - x
// d23 = y + d31 - x
// y = d23 - d31 + x
// d12 = x + d23 - d31 + x
// x = (d12 - d23 + d31) / 2 ---------
// y = (2*d23 - 2*d31 + d12 - d23 + d31) / 2
// y = (d23 - d31 + d12) / 2 --------0
// z = (2*d31 - d12 + d23 - d31) / 2
// z = (d31 - d12 + d23) / 2 ---------
