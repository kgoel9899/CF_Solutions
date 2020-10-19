#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int n = a.size();
        for(int i=0;i<n;i++) {
            char c1 = toupper(a[i]), c2 = toupper(b[i]);
            if(c1 > c2) {
                cout << 1 << endl;
                return 0;
            } else if(c1 < c2) {
                cout << -1 << endl;
                return 0;
            }
        }
        cout << 0 << endl;
    }
}