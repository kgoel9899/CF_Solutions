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
const int N = 2e5 + 5;
vector<int> par(N), sizee(N);
set<int> s;
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
        int n, q;
        cin >> n >> q;
        for(int i=1;i<=n;i++) {
            par[i] = i;
            sizee[i] = 1;
            s.insert(i);
        }
        while(q--) {
            int type, x, y;
            cin >> type >> x >> y;
            if(type == 1) union_sets(x, y);
            else if(type == 2) {
                while(true) {
                    auto it = s.lower_bound(x);
                    if(it == s.end() || *it > y) break;
                    else {
                        union_sets(*it, y);
                        if(*it == y) break;
                        s.erase(*it);
                    }
                }
            } else {
                if(find_set(x) == find_set(y)) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
}