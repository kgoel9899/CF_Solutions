#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 5e6 + 5;
vector<int> sieve(N, 1);
void helper() {
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i=2;i<N;i++) {
        if(sieve[i] == 1) {
            for(int j=2*i;j<N;j+=i) {
                int temp = j;
                while(temp % i == 0) {
                    sieve[j]++;
                    temp /= i;
                }
            }
        } else sieve[i]--;
    }
    for(int i=1;i<N;i++) {
        sieve[i] += sieve[i - 1];
    }
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    helper();
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << sieve[a] - sieve[b] << endl;
    }
}