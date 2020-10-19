#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        int x = log2(r);
        int n = pow(2, x);
        if(l == r) cout << 0 << endl;
        else if(n > l) cout << (n ^ (n - 1)) << endl;
        else {
            while(x > 0) {
                int f = ((l >> x) & 1);
                int s = ((r >> x) & 1);
                if(f != s) break;
                x--;
            }
            x++;
            cout << (int)pow(2, x) - 1 << endl;
        }
    }
}