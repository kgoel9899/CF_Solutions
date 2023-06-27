#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
// #define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
// const int INF = 1e18;

#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }

const int tot = 2;
const int N = 31;
struct Node {
    vector<int> next;
    int leaf;
    Node() {
        next.resize(tot, -1);
        leaf = 0;
    }
    // left child = 0
    // right child = 1
};
vector<Node> trie;
void add_string(int num) {
    int curr = 0;
    for(int i=N;i>=0;i--) {
        int b = ((num >> i) & 1);
        if(trie[curr].next[b] == -1) {
            trie[curr].next[b] = trie.size();
            trie.emplace_back();
        }
        curr = trie[curr].next[b];
    }
    trie[curr].leaf++;
}
void remove_string(int num) {
    int curr = 0;
    vector<pair<int, int>> v;
    v.push_back({0, 0});
    for(int i=N;i>=0;i--) {
        int b = ((num >> i) & 1);
        assert(trie[curr].next[b] != -1);
        curr = trie[curr].next[b];
        v.push_back({curr, b});
    }
    assert(trie[curr].leaf);
    trie[curr].leaf--;
    if(trie[curr].leaf >= 1) return;
    reverse(all(v));
    dbg(v);
    int sz = v.size();
    for(int i=0;i<sz-1;i++) {
        curr = v[i].first;
        if(trie[curr].next[0] == -1 && trie[curr].next[1] == -1) {
            assert(trie[v[i + 1].first].next[v[i].second] == curr);
            trie[v[i + 1].first].next[v[i].second] = -1;
        }
    }
}
int max_xor(int num) {
    int curr = 0, ans = 0;
    for(int i=N;i>=0;i--) {
        int b = ((num >> i) & 1);
        if(curr == -1) return ans;
        // dbg(b, curr);
        if(trie[curr].next[b ^ 1] == -1) curr = trie[curr].next[b];
        else {
            ans += (1 << i);
            curr = trie[curr].next[b ^ 1];
        }
        // dbg(b, curr);
        // break;
    }
    return ans;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        trie.clear();
        trie.emplace_back();
        int q;
        cin >> q;
        while(q--) {
            char c;
            int num;
            cin >> c >> num;
            if(c == '+') add_string(num);
            else if(c == '-') remove_string(num);
            else cout << max(num, max_xor(num)) << endl;
        }
    }
}