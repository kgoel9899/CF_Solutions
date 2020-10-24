#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define vi vector<int>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define pb push_back
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 2e5;
int32_t main() {
    int t = 1;
    cin >> t;
    vi sieve(N, 1);
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i=2;i*i<=N;i++) {
        if(sieve[i] == 1) {
            for(int j=i*i;j<N;j+=i) {
                sieve[j] = 0;
            }
        }
    }
    while(t--) {
        int n;
        cin >> n;
        int sum = n;
        while(true) {
            if(sieve[sum] == 1 && sieve[sum - (n - 1)] == 0) break;
            sum++;
        }
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<n-1;j++) {
                cout << 1 << " ";
            }
            cout << sum - (n - 1) << endl;
        }
        for(int i=0;i<n-1;i++) {
            cout << sum - (n - 1) << " ";
        }
        // return 0;
        int save = sum - (n - 1);
        sum = (n - 1) * (sum - (n - 1));
        // cout << sum << " " << save << endl;
        // return 0;
        // cout << ncurr << endl;
        while(true) {
            if(sieve[sum] == 1 && sieve[sum - (n - 1) * save] == 0) break;
            sum++;
            // cout << sum << endl;
            // return 0;
        }
        cout << sum - (n - 1) * save << endl;
    }
    return 0;
}