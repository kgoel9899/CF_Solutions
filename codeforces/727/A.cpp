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
        int a, b;
        cin >> a >> b;
        queue<int> q;
        q.push(a);
        map<int, int> m;
        m[a] = -1;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            if(f == b) break;
            int x = f * 2;
            if(x <= b && m.find(x) == m.end()) {
                m[x] = f;
                q.push(x);
            }
            int y = f * 10 + 1;
            if(y <= b && m.find(y) == m.end()) {
                m[y] = f;
                q.push(y);
            }
        }
        if(m.find(b) == m.end()) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        vector<int> ans;
        int curr = b;
        while(curr != -1) {
            ans.push_back(curr);
            curr = m[curr];
        }
        reverse(all(ans));
        cout << ans.size() << endl;
        for(auto& i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}