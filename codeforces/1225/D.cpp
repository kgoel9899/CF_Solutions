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

const int N = 1e5 + 5;
vector<int> spf, primes;
void init() {
    spf.clear();
    spf.resize(N);
    for(int i=0;i<N;i++) {
        spf[i] = i;
    }
    primes.clear();
    for(int i=2;i<N;i++) {
        if(spf[i] == i) {
            primes.push_back(i);
            for(int j=i*i;j<N;j+=i) {
                spf[j] = i;
            }
        }
    }
}
int32_t main() {
    fast;
    int tt = 1;
    init();
    // cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int ans = 0;
        map<map<int, int>, int> m;
        for(auto& i : v) {
            map<int, int> a, b;
            int num = i;
            while(num > 1) {
                int ct = 0, fact = spf[num];
                while(num % fact == 0) {
                    num /= fact;
                    ct++;
                }
                ct %= k;
                if(ct) {
                    a[fact] = ct;
                    b[fact] = k - ct;
                }
            }
            if(m.find(b) != m.end()) ans += m[b];
            m[a]++;
            dbg(i, a, b);
        }
        cout << ans << endl;
    }
}