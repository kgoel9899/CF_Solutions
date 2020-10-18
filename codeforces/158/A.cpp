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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int ans = k;
        int i = k;
        while(i < n && v[i] == v[k - 1]) {
            ans++;
            i++;
        }
        int temp = ans;
        for(int i=temp-1;i>=0;i--) {
            if(v[i] == 0) ans--;
            else break;
        }
        cout << ans << endl;
    }
}