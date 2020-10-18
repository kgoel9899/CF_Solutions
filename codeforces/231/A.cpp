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
    int ans = 0;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int sum = a + b + c;
        if(sum >= 2) ans++;
    }
    cout << ans << endl;
}