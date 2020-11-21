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
        // int n, q;
        // cin >> n >> q;
        // string s;
        // cin >> s;
        // s = '#' + s;
        // while(q--) {
        //     int l, r;
        //     cin >> l >> r;
        //     string ch = s.substr(l, r - l + 1);

        // }
        int n;
        cin >> n;
        if(n == 1) cout << 0 << endl;
        else if(n == 2) cout << 1 << endl;
        else if(n == 3) cout << 2 << endl;
        else if(n % 2 == 0) cout << 2 << endl;
        else cout << 3 << endl;
    }
}