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
        for(int i=n;i<=n+80000;i++) {
            string s = to_string(i);
            int flag = 0;
            for(auto j : s) {
                if(j == '0') continue;
                if(i % (j - '0') != 0) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                cout << i << endl;
                break;
            }
        }
    }
}