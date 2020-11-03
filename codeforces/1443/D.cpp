#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int i = n - 2;
        for(;i>=0;i--) {
            if(v[i] > v[i + 1]) break;
        }
        vector<int> vv = v;
        int flag = 0, diff = 0;
        for(;i>=0;i--) {
            v[i] -= diff;
            if(v[i] > v[i + 1]) {
                diff += v[i] - v[i + 1];
                v[i] = v[i + 1];
            }
            if(v[i] < 0) {
                flag = 1;
                break;
            }
        }
        v = vv;
        if(flag == 0) {
            cout << "YES" << endl;
            continue;
        }
        i = 1;
        for(;i<n;i++) {
            if(v[i] > v[i - 1]) break;
        }
        flag = 0, diff = 0;
        for(;i<n;i++) {
            v[i] -= diff;
            if(v[i] > v[i - 1]) {
                diff += v[i] - v[i - 1];
                v[i] = v[i - 1];
            }
            if(v[i] < 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}