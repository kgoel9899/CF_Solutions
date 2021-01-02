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
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        if(a1 > c1) {
            cout << "NO" << endl;
            continue;
        } else c1 -= a1;
        if(a2 > c2) {
            cout << "NO" << endl;
            continue;
        } else c2 -= a2;
        if(a3 > c3) {
            cout << "NO" << endl;
            continue;
        } else c3 -= a3;
        if(a4 > c1 + c3) {
            cout << "NO" << endl;
            continue;
        } else {
            c1 -= a4;
            if(c1 < 0) {
                c3 -= abs(c1);
                c1 = 0;
            }
        }
        if(a5 > c2 + c3) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}