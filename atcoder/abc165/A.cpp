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
    // cin >> t;
    while(t--) {
        int k, a, b;
        cin >> k >> a >> b;
        for(int i=a;i<=b;i++) {
            if(i % k == 0) {
                cout << "OK" << endl;
                return 0;
            }
        }
        cout << "NG" << endl;
    }
}