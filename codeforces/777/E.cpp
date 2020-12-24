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
vector<pair<pair<int, int>, int>> v, fin;
int n, a, b, h;
map<int, int> m;
vector<int> bit(N);
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if(a.first.second == b.first.second) {
        return a.first.first > b.first.first;
    }
    return a.first.second > b.first.second;
}
void update(int ind, int val) {
    while(ind < N) {
        bit[ind] = max(bit[ind], val);
        ind += (ind & (-ind));
    }
}
int query(int ind) {
    int ans = -INF;
    while(ind > 0) {
        ans = max(ans, bit[ind]);
        ind -= (ind & (-ind));
    }
    return ans;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0;i<n;i++) {
            cin >> a >> b >> h;
            v.push_back({{a, b}, h});
        }
        sort(all(v), comp);
        pair<pair<int, int>, int> p = v[0];
        for(int i=1;i<n;i++) {
            if(v[i].first.second == v[i - 1].first.second) {
                p.first.first = v[i].first.first;
                p.second += v[i].second;
            } else {
                fin.push_back(p);
                p = v[i];
            }
        }
        if(fin.size() != 0) {
            pair<pair<int, int>, int> ch = fin.back();
            if(ch != p) fin.push_back(p);
        } else fin.push_back(p);
        for(auto i : fin) {
            m[i.first.first];
            m[i.first.second];
        }
        int rank = 1;
        for(auto i : m) {
            m[i.first] = rank++;
        }
        n = fin.size();
        for(int i=0;i<n;i++) {
            fin[i].first.first = m[fin[i].first.first];
            fin[i].first.second = m[fin[i].first.second];
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            int curr = fin[i].second + query(fin[i].first.second - 1);
            ans = max(ans, curr);
            update(fin[i].first.first, curr);
        }
        cout << ans << endl;
    }
}