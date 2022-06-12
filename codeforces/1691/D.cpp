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

// editorial
int n;
vector<int> v, tree1, tree2;
vector<int> pref, suff;
void build1(int st, int end, int node) {
    if(st == end) {
        tree1[node] = pref[st];
        return;
    }
    int mid = (st + end) / 2;
    build1(st, mid, 2 * node);
    build1(mid + 1, end, 2 * node + 1);
    tree1[node] = max(tree1[2 * node], tree1[2 * node + 1]);
}
int query1(int st, int end, int l, int r, int node) {
    if(st > r || end < l) return -INF;
    if(st >= l && end <= r) return tree1[node];
    int mid = (st + end) / 2;
    return max(query1(st, mid, l, r, 2 * node), query1(mid + 1, end, l, r, 2 * node + 1));
}
void build2(int st, int end, int node) {
    if(st == end) {
        tree2[node] = suff[st];
        return;
    }
    int mid = (st + end) / 2;
    build2(st, mid, 2 * node);
    build2(mid + 1, end, 2 * node + 1);
    tree2[node] = max(tree2[2 * node], tree2[2 * node + 1]);
}
int query2(int st, int end, int l, int r, int node) {
    if(st > r || end < l) return -INF;
    if(st >= l && end <= r) return tree2[node];
    int mid = (st + end) / 2;
    return max(query2(st, mid, l, r, 2 * node), query2(mid + 1, end, l, r, 2 * node + 1));
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n;
        v.clear();
        v.resize(n);
        tree1.clear();
        tree1.resize(4 * n);
        tree2.clear();
        tree2.resize(4 * n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<int> nge(n, n), pge(n, -1);
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && v[st.top()] <= v[i]) {
                st.pop();
            }
            if(!st.empty()) pge[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) {
            st.pop();
        }
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && v[st.top()] <= v[i]) {
                st.pop();
            }
            if(!st.empty()) nge[i] = st.top();
            st.push(i);
        }
        dbg(pge);
        dbg(nge);
        pref.clear();
        pref.resize(n);
        suff.clear();
        suff.resize(n);
        pref[0] = v[0];
        for(int i=1;i<n;i++) {
            pref[i] = pref[i - 1] + v[i];
        }
        suff[n - 1] = v[n - 1];
        for(int i=n-2;i>=0;i--) {
            suff[i] = suff[i + 1] + v[i];
        }
        dbg(pref);
        dbg(suff);
        build1(0, n - 1, 1);
        build2(0, n - 1, 1);
        dbg(tree1);
        dbg(tree2);
        // tree1 = pref
        // tree2 = suff
        int ok = 1;
        for(int i=0;i<n;i++) {
            int l = query2(0, n - 1, pge[i] + 1, i, 1) - suff[i];
            int r = query1(0, n - 1, i, nge[i] - 1, 1) - pref[i];
            dbg(pge[i] + 1, i, l);
            dbg(i, nge[i] - 1, r);
            if(l + r > 0) ok = 0;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
// 1
// 3
// 5 2 5