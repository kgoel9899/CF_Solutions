#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if(y <= x) {
            cout << "YES" << endl;
            continue;
        }
        if(x == 1) {
            cout << "NO" << endl;
            continue;
        }
        if(x % 2 == 0) {
            int nx = 3 * x / 2;
            if(nx % 2 == 0) cout << "YES" << endl;
            else {
                if(nx == y) cout << "YES" << endl;
                else if(nx - 1 == x) cout << "NO" << endl;
                else cout << "YES" << endl;
            }
        } else {
            x--;
            int nx = 3 * x / 2;
            if(nx % 2 == 0) cout << "YES" << endl;
            else {
                if(nx == y) cout << "YES" << endl;
                else if(nx - 1 == x) cout << "NO" << endl;
                else cout << "YES" << endl;
            }
        }
    }
}