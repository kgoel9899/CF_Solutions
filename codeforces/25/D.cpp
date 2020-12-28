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
const int N = 1005;
vector<int> par(N), sizee(N);
int find_set(int v) {
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(sizee[a] < sizee[b]) swap(a, b);
        par[b] = a;
        sizee[a] += sizee[b];
    }
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) {
            par[i] = i;
            sizee[i] = 1;
        }
        vector<pair<int, int>> v1, v2;
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            if(find_set(a) == find_set(b)) v1.push_back({a, b});
            else union_sets(a, b);
        }
        for(int i=2;i<=n;i++) {
            if(find_set(1) != find_set(i)) {
                v2.push_back({1, i});
                union_sets(1, i);
            }
        }
        cout << v1.size() << endl;
        // assert(v1.size() == v2.size());
        for(int i=0;i<v1.size();i++) {
            cout << v1[i].first << " " << v1[i].second << " " << v2[i].first << " " << v2[i].second << endl;
        }
    }
}