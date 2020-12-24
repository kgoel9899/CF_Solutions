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
const int N = 1e5 + 5;
int n;
map<int, map<int, int>> m;
void update(int ind, int num, int val) {
    while(ind < N) {
        m[num][ind] += val;
        ind += (ind & (-ind));
    }
}
int query(int ind, int num) {
    int ans = 0;
    while(ind > 0) {
        ans += m[num][ind];
        ind -= (ind & (-ind));
    }
    return ans;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    vector<vector<int>> v;
    map<int, int> mp;
    while(t--) {
        cin >> n;
        while(n--) {
            int a, t, x;
            cin >> a >> t >> x;
            v.push_back({a, t, x});
            mp[t];
        }
        n = v.size();
        int rank = 1;
        for(auto i : mp) {
            mp[i.first] = rank++;
        }
        for(int i=0;i<n;i++) {
            v[i][1] = mp[v[i][1]];
        }
        for(int i=0;i<n;i++) {
            int a = v[i][0];
            int t = v[i][1];
            int x = v[i][2];
            if(a == 1) update(t, x, 1);
            else if(a == 2) update(t, x, -1);
            else cout << query(t, x) << endl;
        }
    }
}