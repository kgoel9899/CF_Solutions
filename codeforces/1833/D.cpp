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

void best_vec(vector<int>& a, vector<int>& b) {
    assert(a.size() == b.size());
    int n = a.size();
    for(int i=0;i<n;i++) {
        if(a[i] == b[i]) continue;
        if(a[i] > b[i]) return;
        break;
    }
    a = b;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int pos = -1;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            if(v[i] == n) pos = i;
        }
        if(n == 1) {
            cout << v[0] << endl;
            continue;
        }
        if(pos == 0) {
            for(int i=0;i<n;i++) {
                if(v[i] == n - 1) pos = i;
            }
        }
        assert(pos);
        for(int i=pos;i<n;i++) {
            cout << v[i] << " ";
        }
        if(pos == 1) {
            cout << v[0] << endl;
            continue;
        }
        vector<int> best(v.begin(), v.begin() + pos - 1);
        best.insert(best.begin(), v[pos - 1]);
        for(int i=pos-2;i>=0;i--) {
            vector<int> temp(v.begin() + i, v.begin() + pos);
            reverse(all(temp));
            for(int j=0;j<i;j++) {
                temp.push_back(v[j]);
            }
            best_vec(best, temp);
        }
        if(pos == n - 1) {
            vector<int> best1(v.begin(), v.begin() + pos);
            best_vec(best, best1);
        }
        for(auto& i : best) {
            cout << i << " ";
        }
        cout << endl;
    }
}