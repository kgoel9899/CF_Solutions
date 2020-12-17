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
        int n;
        cin >> n;
        vector<int> v(n);
        int even = 0, odd = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            if(i % 2 == 0) even += v[i];
            else odd += v[i];
        }
        vector<int> ans(n, 1);
        if(odd >= even) {
            for(int i=1;i<n;i+=2) {
                ans[i] = v[i];
            }
        } else {
            for(int i=0;i<n;i+=2) {
                ans[i] = v[i];
            }
        }
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}