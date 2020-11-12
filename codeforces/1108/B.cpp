#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int a = v[n - 1], b = INT_MAX;
        for(int i=n-2;i>=0;i--) {
            if(v[i] == v[i + 1] || a % v[i] != 0) {
                b = v[i];
                break;
            }
        }
        cout << a << " " << b << endl;
    }
}