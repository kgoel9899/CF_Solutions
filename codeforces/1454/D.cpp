#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 1e6;
vector<int> sieve(N, 1);
void helper() {
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i=2;i*i<=N;i++) {
        if(sieve[i] == 1) {
            for(int j=i*i;j<N;j+=i) {
                sieve[j] = 0;
            }
        }
    }
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    helper();
    while(t--) {
        int n;
        cin >> n;
        map<int, int> m;
        int nn = n;
        while(n % 2 == 0) {
            m[2]++;
            n /= 2;
        }
        int sq = sqrt(n) + 10;
        for(int i=3;i<sq;i+=2) {
            if(sieve[i] == 1) {
                while(n % i == 0) {
                    m[i]++;
                    n /= i;
                }
            }
        }
        int mx = 1, val;
        for(auto i : m) {
            if(i.second > mx) {
                mx = i.second;
                val = i.first;
            }
        }
        if(m.size() == 0) {
            mx = 1;
            val = nn;
        }
        cout << mx << endl;
        if(m.size() == 0) cout << val << endl;
        else {
            for(int i=0;i<mx-1;i++) {
                cout << val << " ";
                nn /= val;
            }
            cout << nn << endl;
        }
    }
}