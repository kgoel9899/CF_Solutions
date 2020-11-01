#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        if(k == n) cout << 1000000000 << endl;
        else if(k == 0) {
            if(v[0] > 1) cout << 1 << endl;
            else cout << -1 << endl;
        } else {
            k--;
            if(v[k + 1] == v[k]) cout << -1 << endl;
            else cout << v[k] << endl;
        }
    }
}