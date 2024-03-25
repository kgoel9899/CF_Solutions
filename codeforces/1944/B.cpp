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

#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }

int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(2 * n);
        for(int i=0;i<2*n;i++) {
            cin >> v[i];
        }
        map<int, int> m, m1;
        for(int i=0;i<2*n;i++) {
            if(i < n) m[v[i]]++;
            else m1[v[i]]++;
        }
        vector<int> two, two1, one;
        for(auto& i : m) {
            if(i.second == 2) two.push_back(i.first);
            else one.push_back(i.first);
        }
        for(auto& i : m1) {
            if(i.second == 2) two1.push_back(i.first);
        }
        assert(two.size() == two1.size());
        vector<int> l, r;
        int ind = 0;
        while(l.size() < 2 * k && ind < two.size()) {
            l.push_back(two[ind]);
            l.push_back(two[ind]);
            r.push_back(two1[ind]);
            r.push_back(two1[ind]);
            ind++;
        }
        ind = 0;
        while(l.size() < 2 * k) {
            l.push_back(one[ind]);
            r.push_back(one[ind]);
            ind++;
        }
        for(auto& i : l) {
            cout << i << " ";
        }
        cout << endl;
        for(auto& i : r) {
            cout << i << " ";
        }
        cout << endl;
    }
}