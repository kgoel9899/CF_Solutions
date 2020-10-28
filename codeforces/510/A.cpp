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
        int n, m;
        cin >> n >> m;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i % 2 == 0) cout << '#';
                else {
                    if((i - 1) % 4 == 0) {
                        if(j == m - 1) cout << '#';
                        else cout << '.';
                    } else {
                        if(j == 0) cout << '#';
                        else cout << '.';
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}