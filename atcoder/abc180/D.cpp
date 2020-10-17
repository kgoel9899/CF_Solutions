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
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int ans1 = 0, temp = x;
        while(true) {
            // temp *= a;
            if(y % a == 0) {
                if(temp <= y / a - 1) ans1++;
                else break;
            } else {
                if(temp <= y / a) ans1++;
                else break;
            }
            temp *= a;
            // if(temp < y) ans1++;
            // else break;
        }
        int ans2 = 0;
        int ta = (y - x) / b;
        if((y - x) % b == 0) ta--;
        ans2 += ta;
        int newt = (y - x) - b * ta;
        temp = x;
        while(true) {
            // temp *= a;
            if((x + newt) % a == 0) {
                if(temp <= (x + newt) / a - 1) ans2++;
                else break;
            } else {
                if(temp <= (x + newt) / a - 1) ans2++;
                else break;
            }
            temp *= a;
            // if(temp < x + newt) ans2++;
            // else break;
        }
        // cout << ans1 << " " << ans2 << endl;
        cout << max(ans1, ans2) << endl;
    }
}