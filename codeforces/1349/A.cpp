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
// editorial hint
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    const int N = 2e5 + 5;
    vector<int> spf(N);
    for(int i=0;i<N;i++) {
        spf[i] = i;
    }
    for(int i=2;i*i<=N;i++) {
        if(spf[i] == i) {
            for(int j=i*i;j<N;j+=i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        map<int, multiset<int>> m;
        for(auto i : v) {
            int temp = i;
            while(temp > 1) {
                int curr = spf[temp], ct = 0;
                while(temp % curr == 0) {
                    temp /= curr;
                    ct++;
                }
                if(ct) m[curr].insert(ct);
            }
        }
        int ans = 1;
        for(auto i : m) {
            if(i.second.size() == n - 1) ans *= pow(i.first, *(i.second.begin()));
            else if(i.second.size() == n) {
                auto it = i.second.begin();
                it++;
                ans *= pow(i.first, *it);
            }
        }
        cout << ans << endl;
    }
}