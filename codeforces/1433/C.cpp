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
        map<int, int> m;
        int mx = INT_MIN, ind = -1;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            m[v[i]]++;
            if(v[i] > mx) {
                mx = v[i];
                ind = i + 1;
            }
        }
        if(m.size() == 1) cout << -1 << endl;
        else {
            for(int i=0;i<n;i++) {
                if(v[i] == mx) {
                    if(i == 0) {
                        if(v[1] < mx) {
                            cout << 1 << endl;
                            break;
                        }
                    } else if(i == n - 1) {
                        if(v[n - 2] < mx) {
                            cout << n << endl;
                            break;
                        }
                    } else {
                        if(v[i - 1] < mx || v[i + 1] < mx) {
                            cout << i + 1 << endl;
                            break;
                        }
                    }
                }
            }
            // if(v[0] == mx) {
            //     if(v[1] < mx) cout << 1 << endl;
            // } else if(v[n - 1] == mx) {
            //     if(v[n - 2] < mx) cout << n << endl;
            // } else {
            //     for(int i=1;i<n-1;i++) {
            //         if(v[i] == mx) {
            //             if(v[i + 1] < mx || v[i - 1] < mx) {
            //                 cout << i + 1 << endl;
            //                 break;
            //             }
            //         }
            //     }
            // }
        }
    }
}