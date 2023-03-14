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
        int n, m, p;
        cin >> n >> m >> p;
        string s;
        cin >> s;
        string ops;
        cin >> ops;
        vector<int> group(n);
        stack<int> st;
        for(int i=0;i<n;i++) {
            if(s[i] == '(') st.push(i);
            else {
                auto ind = st.top();
                st.pop();
                group[i] = ind;
                group[ind] = i;
            }
        }
        assert(st.empty());
        dbg(group);
        set<int> s1;
        for(int i=0;i<n;i++) {
            s1.insert(i);
        }
        auto it = s1.begin();
        p--;
        while(p > 0) {
            it++;
            p--;
        }
        dbg(s1);
        for(auto& i : ops) {
            if(i == 'L') it--;
            else if(i == 'R') it++;
            else {
                int curr = *it;
                int fin = group[curr];
                if(curr < fin) {
                    while(it != s1.end() && *it <= fin) {
                        auto it1 = it;
                        it++;
                        s1.erase(it1);
                    }
                    if(it == s1.end()) it--;
                } else {
                    int ok = 0;
                    while(*it >= fin) {
                        auto it1 = it;
                        if(it == s1.begin()) {
                            ok = 1;
                            it++;
                        } else it--;
                        s1.erase(it1);
                        if(ok) break;
                    }
                    if(!ok) it++;
                    if(it == s1.end()) it--;
                }
            }
        }
        for(auto& i : s1) {
            cout << s[i];
        }
        cout << endl;
    }
}