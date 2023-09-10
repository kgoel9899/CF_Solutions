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

vector<int> tree, v;
int n, newn;
void build(int st, int end, int tn) {
    if(st == end) {
        tree[tn] = v[st];
        // dbg(tn, st);
        return;
    }
    int mid = (st + end) / 2;
    build(st, mid, 2 * tn);
    build(mid + 1, end, 2 * tn + 1);
    tree[tn] = __gcd(tree[2 * tn], tree[2 * tn + 1]);
}
int query(int st, int end, int tn, int left, int right) {
    if(st > right || end < left) return 0;
    if(st >= left && end <= right) return tree[tn];
    int mid = (st + end) / 2;
    return __gcd(query(st, mid, 2 * tn, left, right), query(mid + 1, end, 2 * tn + 1, left, right));
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        cin >> n;
        v.clear();
        v.resize(n);
        int g = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            g = __gcd(g, v[i]);
        }
        for(int i=0;i<n;i++) {
            v[i] /= g;
            v.push_back(v[i]); // to prevent complexities from circular array
        }
        newn = n * 2;
        tree.clear();
        tree.resize(4 * newn);
        build(0, v.size() - 1, 1);
        int ans = 0;
        for(int i=0;i<n;i++) {
            int beg = i, end = i + n - 1, curr = INF;
            while(beg <= end) {
                int mid = (beg + end) / 2;
                if(query(0, v.size() - 1, 1, i, mid) > 1) beg = mid + 1;
                else {
                    curr = min(curr, mid - i);
                    end = mid - 1;
                }
            }
            ans = max(ans, curr); // max of all the ops to make current element = 1
        }
        cout << ans << endl;
    }
}