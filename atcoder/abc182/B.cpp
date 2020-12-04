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
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int mxi = *max_element(v.begin(), v.end());
        int num, mx = 0;
        for(int i=2;i<=mxi;i++) {
            int curr = 0;
            for(int j=0;j<n;j++) {
                if(v[j] % i == 0) curr++;
            }
            if(curr > mx) {
                mx = curr;
                num = i;
            }
        }
        cout << num << endl;
    }
}