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
        int n, m;
        cin >> n >> m;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int num;
                cin >> num;
                if((i + j) % 2 == 0) {
                    if(num % 2 == 1) cout << num + 1 << " ";
                    else cout << num << " ";
                } else {
                    if(num % 2 == 0) cout << num + 1 << " ";
                    else cout << num << " ";
                }
            }
            cout << endl;
        }
    }
}