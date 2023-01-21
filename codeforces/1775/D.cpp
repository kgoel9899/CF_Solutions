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
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        const int N = 3e5 + 5;
        vector<int> sieve(N);
        sieve[1] = 1;
        for(int i=2;i<N;i++) {
            if(!sieve[i]) {
                sieve[i] = i;
                for(int j=i*i;j<N;j+=i) {
                    if(!sieve[j]) sieve[j] = i;
                }
            }
        }
        vector<vector<int>> adj(2 * N);
        for(int i=0;i<n;i++) {
            int val = v[i];
            while(sieve[val] > 1) {
                adj[i].push_back(sieve[val] + N);
                adj[sieve[val] + N].push_back(i);
                val /= sieve[val];
            }
        }
        queue<int> q;
        q.push(s);
        vector<int> par(2 * N, -1), dist(2 * N, -1);
        dist[s] = 1;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            for(auto& i : adj[f]) {
                if(dist[i] == -1) {
                    dist[i] = dist[f] + 1;
                    par[i] = f;
                    q.push(i);
                }
            }
        }
        if(dist[t] == -1) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        int node = t;
        while(node != -1) {
            if(node < n) ans.push_back(node);
            node = par[node];
        }
        reverse(all(ans));
        cout << ans.size() << endl;
        for(auto& i : ans) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}