#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e9;
const int N = 100 * 100 + 5;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int sum = 0;
        for(int i=0;i<n;i++) {
            int x;
            cin >> x;
            sum += x;
        }
        if(sum > 0) cout << "HARD" << endl;
        else cout << "EASY" << endl;
    }
}