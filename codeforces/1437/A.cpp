#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    int t = 1;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        int a = r + 1;
        if(l >= double(a) / 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}