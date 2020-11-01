#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 3e5 + 10;
vector<int> v(N);
int ans = 0, n;
void erase(int i) {
    if(i == 0 || i == n + 1) return;
    if(v[i] > v[i - 1] && v[i] > v[i + 1]) ans -= v[i];
    if(v[i] < v[i - 1] && v[i] < v[i + 1]) ans += v[i];
}
void insert(int i) {
    if(i == 0 || i == n + 1) return;
    if(v[i] > v[i - 1] && v[i] > v[i + 1]) ans += v[i];
    if(v[i] < v[i - 1] && v[i] < v[i + 1]) ans -= v[i];
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int q;
        cin >> n >> q;
        for(int i=1;i<=n;i++) {
            cin >> v[i];
        }
        v[0] = -1;
        v[n + 1] = -1;
        ans = 0;
        for(int i=1;i<=n;i++) {
            if(v[i] > v[i - 1] && v[i] > v[i + 1]) ans += v[i];
            else if(v[i] < v[i - 1] && v[i] < v[i + 1]) ans -= v[i];
        }
        cout << ans << endl;
        while(q--) {
            int l, r;
            cin >> l >> r;
            erase(l);
            erase(l - 1);
            erase(l + 1);
            if(l != r) {
                if(l + 2 == r) erase(r);
                else if(l + 2 < r) {
                    erase(r);
                    erase(r - 1);
                }
                erase(r + 1);
            }
            swap(v[l], v[r]);
            insert(l);
            insert(l - 1);
            insert(l + 1);
            if(l != r) {
                if(l + 2 == r) insert(r);
                else if(l + 2 < r) {
                    insert(r);
                    insert(r - 1);
                }
                insert(r + 1);
            }
            cout << ans << endl;
        }
    }
}