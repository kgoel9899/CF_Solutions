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
    cin >> t;
    while(t--) {
        int n, un, x = 0;
        cin >> n >> un;
        for(int i=0;i<n;i++) {
            int num;
            cin >> num;
            if(un % 2 == 0) {
                if(num < un / 2) cout << 0 << " ";
                else if(num > un / 2) cout << 1 << " ";
                else {
                    if(x == 0) cout << 0 << " ";
                    else cout << 1 << " ";
                    x ^= 1;
                }
            } else {
                if(num <= un / 2) cout << 0 << " ";
                else if(num > un / 2) cout << 1 << " ";
                else {
                    if(x == 0) cout << 0 << " ";
                    else cout << 1 << " ";
                    x ^= 1;
                }
            }
        }
        cout << endl;
    }
}