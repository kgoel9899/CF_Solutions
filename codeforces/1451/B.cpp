#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
// #define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
// const int N = 1e7 + 5;
// vector<int> sieve(N, 1), fact(N);
// vector<int> a(N), b(N);
// void helper() {
//     sieve[0] = 0;
//     sieve[1] = 0;
//     for(int i=2;i<N;i++) {
//         if(sieve[i] == 1) {
//             fact[i] = i;
//             for(int j=2*i;j<N;j+=i) {
//                 sieve[j] = 0;
//                 fact[j] = i;
//             }
//         }
//     }
// }
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    // helper();
    while(t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        s = '#' + s;
        while(q--) {
            int l, r;
            cin >> l >> r;
            // string ch = s.substr(l, r - l + 1);
            // int x = 0;
            int flag = 0;
            int last = -1;
            int i = 1;
            for(;i<=n&&l<r;i++) {
                if(s[i] == s[l]) {
                    if(last != -1) {
                        if(i - last > 1) flag = 1;
                    }
                    last = i;
                    l++;
                }
            }
            int done = 0;
            for(;i<=n;i++) {
                if(s[i] == s[r]) {
                    if(flag == 1) {
                        done = 1;
                        break;
                    } else {
                        if(i - last > 1) {
                            done = 1;
                            break;
                        }
                    }
                }
            }
            if(done == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}