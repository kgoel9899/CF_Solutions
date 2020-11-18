#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int mx = 1e5 + 5;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> sieve(mx, 1);
        sieve[1] = 0;
        sieve[0] = 0;
        for(int i=2;i*i<=mx;i++) {
            if(sieve[i] == 1) {
                for(int j=i*i;j<mx;j+=i) {
                    sieve[j] = max(sieve[j], sieve[i] + 1);
                }
            }
        }
        set<int> s;
        for(int i=2;i<=n+1;i++) {
            s.insert(sieve[i]);
        }
        cout << s.size() << endl;
        for(int i=2;i<=n+1;i++) {
            cout << sieve[i] << " ";
        }
        cout << endl;
    }
}

// 2 = 1
// 3 = 1
// 4 = 2
// 5
// 6 = 2
// 7 = 1
// 8 = 
// 9
// 10
// 11
// 12
// 13
// 14
// 15
// 16
// 17
// 18