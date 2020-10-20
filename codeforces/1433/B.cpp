#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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
        int flag = 0, ct = 0;
        for(int i=0;i<n;i++) {
            if(v[i] == 1) flag = 1;
            else {
                if(flag == 1) ct++;
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(v[i] == 1) break;
            ct--;
        }
        cout << ct << endl;
    }
}