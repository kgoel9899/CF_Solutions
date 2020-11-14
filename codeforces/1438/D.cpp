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
        int n;
        cin >> n;
        vector<int> v(n);
        int xr = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            xr ^= v[i];
        }
        if(n % 2 == 0 && xr != 0) {
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        vector<vector<int>> ans;
        for(int i=0;i+2<n;i+=2) {
            ans.push_back({i + 1, i + 2, i + 3});
        }
        // return 0;
        // if(n % 2 == 1) {
            // cout << n << " " << endl;
            if(n % 2 == 0) n--;
            for(int i=n-3;i-2>=0;i-=2) {
                // cout << "asdfg " << i << endl;
                ans.push_back({i + 1, i, i - 1});
            }
        // }
        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }
    }
}

// 4 2 1 7 2
// 7 7 7 7 2
// 7 7 2 2 2

// 1 2 3 4 5 6
// a a b b b c
