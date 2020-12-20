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
        string a, b;
        cin >> a >> b;
        int r = 0, bb = 0;
        for(int i=0;i<n;i++) {
            if(a[i] > b[i]) r++;
            else if(a[i] < b[i]) bb++;
        }
        if(r > bb) cout << "RED" << endl;
        else if(r < bb) cout << "BLUE" << endl;
        else cout << "EQUAL" << endl;
    }
}