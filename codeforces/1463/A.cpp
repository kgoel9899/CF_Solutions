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
        // int n;
        // cin >> n;
        // vector<int> v(n);
        // for(int i=0;i<n;i++) {
        //     cin >> v[i];
        // }
        int a, b, c;
        cin >> a >> b >> c;
        int reqd = a + b + c - 3;
        reqd += 3;
        int div = reqd / 9;
        if(min({a, b, c}) < div) {
            cout << "NO" << endl;
            continue;
        }
        if(reqd != 0 && reqd % 9 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}