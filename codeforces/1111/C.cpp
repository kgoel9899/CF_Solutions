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

vector<int> v;
int solve(int l, int r, int a, int b) {
    int ind1 = lower_bound(all(v), l) - v.begin();
    int ind2 = upper_bound(all(v), r) - v.begin();
    ind2--;
    int tot = ind2 - ind1 + 1;
    int op1;
    if(tot > 0) op1 = b * tot * (r - l + 1);
    else op1 = a;
    if(l == r || tot == 0) return op1;
    int mid = (l + r) / 2;
    int op2 = solve(l, mid, a, b) + solve(mid + 1, r, a, b);
    return min(op1, op2);
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        v.clear();
        v.resize(k);
        for(int i=0;i<k;i++) {
            cin >> v[i];
        }
        sort(all(v));
        cout << solve(1, (1ll << n), a, b) << endl;
    }
}