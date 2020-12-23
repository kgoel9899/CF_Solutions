#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int K = 15;
const int N = 1e5 + 5;
int n, k;
int bit[K][N];
vector<int> v(N);
int mx;
void update(int kval, int ind, int val) {
    while(ind <= mx) {
        bit[kval][ind] += val;
        ind += (ind & (-ind));
    }
}
int query(int kval, int ind) {
    int ans = 0;
    while(ind > 0) {
        ans += bit[kval][ind];
        ind -= (ind & (-ind));
    }
    return ans;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        mx = *max_element(v.begin(), v.end());
        for(int i=0;i<n;i++) {
            update(1, v[i], 1);
            for(int j=2;j<=k+1;j++) {
                update(j, v[i], query(j - 1, v[i] - 1));
            }
        }
        cout << query(k + 1, mx) << endl;
    }
}