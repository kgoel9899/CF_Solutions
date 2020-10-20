#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> fact(n + 1);
        fact[0] = 1;
        fact[1] = 1;
        for(int i=2;i<=n;i++) {
            fact[i] = i * fact[i - 1];
        }
        cout << fact[n] / (n * n / 2) << endl;
    }
}