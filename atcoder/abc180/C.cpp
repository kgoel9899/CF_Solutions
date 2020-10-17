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
        int n;
        cin >> n;
        set<int> s;
        for(int i=1;i*i<=n;i++) {
            if(n % i == 0) {
                s.insert(i);
                s.insert(n / i);
            }
        }
        for(auto i : s) {
            cout << i << endl;
        }
    }
}