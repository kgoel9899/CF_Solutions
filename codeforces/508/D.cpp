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
        map<string, multiset<string>> adj;
        map<string, int> in, out;
        for(int i=0;i<n;i++) {
            string s;
            cin >> s;
            adj[s.substr(0, 2)].insert(s.substr(1));
            in[s.substr(1)]++;
            out[s.substr(0, 2)]++;
        }
        int bad = 0;
        string beg = "", end = "";
        int ind = 0, outd = 0, same = 0;
        for(auto& x : adj) {
            string i = x.first;
            if(in[i] == out[i]) same++;
            else if(in[i] - out[i] == 1) {
                if(ind) bad = 1;
                ind++;
                end = i;
            } else if(out[i] - in[i] == 1) {
                if(outd) bad = 1;
                outd++;
                beg = i;
            } else bad = 1;
        }
        dbg(adj);
        dbg(bad, same, ind, outd);
        if(bad) {
            cout << "NO" << endl;
            continue;
        }
        stack<string> st;
        if(beg == "") beg = adj.begin()->first;
        st.push(beg);
        vector<string> ans;
        while(!st.empty()) {
            auto f = st.top();
            if(adj[f].empty()) {
                ans.push_back(f);
                st.pop();
            } else {
                auto v = *adj[f].begin();
                adj[f].erase(adj[f].begin());
                st.push(v);
            }
        }
        dbg(ans);
        for(auto& i : adj) {
            if(i.second.size()) {
                bad = 1;
                break;
            }
        }
        if(bad) {
            cout << "NO" << endl;
            continue;
        }
        reverse(all(ans));
        string fin = ans[0];
        dbg(ans);
        for(int i=1;i<ans.size();i++) {
            fin += ans[i][1];
        }
        cout << "YES" << endl;
        cout << fin << endl;
    }
}