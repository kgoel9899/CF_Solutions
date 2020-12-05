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
        int d, k;
        cin >> d >> k;
        int x = 0, y = 0;
        while(true) {
            if(x <= y && (x + k) * (x + k) + y * y <= d * d) x += k;
            else if(x > y && (y + k) * (y + k) + x * x <= d * d) y += k;
            else break;
        }
        if(x == y) cout << "Utkarsh" << endl;
        else cout << "Ashish" << endl;
    }
}