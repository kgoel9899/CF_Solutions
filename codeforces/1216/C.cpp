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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;
        int x5, y5, x6, y6;
        cin >> x5 >> y5 >> x6 >> y6;
        int ar = (x2 - x1) * (y2 - y1);
        int ax = max(x1, x3);
        int ay = max(y1, y3);
        int bx = min(x2, x4);
        int by = min(y2, y4);
        int temp = (bx - ax) * (by - ay);
        if(temp >= 0 && ax >= x1 && ax <= x2 && ay >= y1 && ay <= y2 && bx >= x1 && bx <= x2 && by >= y1 && by <= y2) ar -= temp;
        ax = max(x1, x5);
        ay = max(y1, y5);
        bx = min(x2, x6);
        by = min(y2, y6);
        temp = (bx - ax) * (by - ay);
        if(temp >= 0 && ax >= x1 && ax <= x2 && ay >= y1 && ay <= y2 && bx >= x1 && bx <= x2 && by >= y1 && by <= y2) ar -= temp;
        if((x5 <= x4 && y6 <= y4) || (x3 <= x6 && y4 <= y6)) {
            ax = max({x3, x5, x1});
            ay = max({y3, y5, y1});
            bx = min({x4, x6, x2});
            by = min({y4, y6, y2});
            int temp = (bx - ax) * (by - ay);
            if(temp >= 0 && ax >= x1 && ax <= x2 && ay >= y1 && ay <= y2 && bx >= x1 && bx <= x2 && by >= y1 && by <= y2) ar += temp;
        } 
        if(ar > 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}