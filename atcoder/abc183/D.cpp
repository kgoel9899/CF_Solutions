#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 2e5 + 10;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, w;
        cin >> n >> w;
        vector<int> s(n), t(n), p(n);
        for(int i=0;i<n;i++) {
            cin >> s[i] >> t[i] >> p[i];
        }
        vector<int> sum(N);
        for(int i=0;i<n;i++) {
            sum[s[i]] += p[i];
            sum[t[i]] -= p[i];
        }
        for(int i=1;i<N;i++) {
            sum[i] += sum[i - 1];
        }
        int flag = 0;
        for(int i=0;i<N;i++) {
            if(sum[i] > w) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}