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
        int s = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            s += v[i];
        }
        for(int i=0;i<n;i++) {
            if(s % (n - i) == 0) {
                int curr = 0, flag = 0;
                for(int j=0;j<n;j++) {
                    curr += v[j];
                    if(curr > s / (n - i)) {
                        flag = 1;
                        break;
                    }
                    if(curr == s / (n - i)) curr = 0;
                }
                if(flag == 0) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}