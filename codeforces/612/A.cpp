#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 1e5 + 5;
vector<int> v(N, -1);
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, p, q;
        cin >> n >> p >> q;
        string s;
        cin >> s;
        if(n % p == 0) {
            cout << n / p << endl;
            for(int i=0;i<n;i+=p) {
                cout << s.substr(i, p) << endl;
            }
        } else if(n % q == 0) {
            cout << n / q << endl;
            for(int i=0;i<n;i+=q) {
                cout << s.substr(i, q) << endl;
            }
        } else {
            if(p > q) swap(p, q);
            int a = n / q;
            int flag = 0;
            for(int i=0;i<=a;i++) {
                if((n - q * i) % p == 0) {
                    cout << i + (n - q * i) / p << endl;
                    int last = 0;
                    for(int j=0;j<i;j++) {
                        cout << s.substr(last, q) << endl;
                        last += q;
                    }
                    for(int j=last;j<n;j+=p) {
                        cout << s.substr(j, p) << endl;
                    }
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) cout << -1 << endl;
            // if(n % p == q - p) {
            //     cout << n / p << endl;
            //     for(int i=0;i<n-q;i+=p) {
            //         cout << s.substr(i, p) << endl;
            //     }
            //     cout << s.substr(n - q) << endl;
            // } else cout << -1 << endl;
        }
    }
}