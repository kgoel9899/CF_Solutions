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
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, vector<int>> m;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            m[v[i]].push_back(i);
        }
        int ok = 1;
        if(m.find(1) != m.end() && m[1].size() >= 2) ok = 0;
        for(auto& i : m) {
            if(i.second.size() >= 3) ok = 0;
        }
        if(!ok) {
            cout << "NO" << endl;
            continue;
        }
        set<int> s1, s2;
        for(int i=1;i<=n;i++) {
            s1.insert(i);
            s2.insert(i);
        }
        vector<int> ans1(n), ans2(n);
        dbg(m);
        for(auto& i : m) {
            if(i.second.size() == 1) {
                if(s1.find(i.first) != s1.end() && s2.find(i.first) != s2.end()) {
                    ans1[i.second[0]] = i.first;
                    ans2[i.second[0]] = i.first;
                    s1.erase(i.first);
                    s2.erase(i.first);
                } else {
                    ok = 0;
                    break;
                }
            } else {
                int ind1 = i.second[0], ind2 = i.second[1];
                dbg(ind1, ind2);
                s1.erase(i.first);
                s2.erase(i.first);
                ans1[ind1] = i.first;
                assert(s1.size());
                assert(s2.size());
                ans2[ind1] = *s2.begin();
                ans1[ind2] = *s1.begin();
                ans2[ind2] = i.first;
                s1.erase(s1.begin());
                s2.erase(s2.begin());
                if(ans1[ind1] < ans2[ind1] || ans1[ind2] > ans2[ind2]) {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) {
            cout << "YES" << endl;
            for(auto& i : ans1) {
                cout << i << " ";
            }
            cout << endl;
            for(auto& i : ans2) {
                cout << i << " ";
            }
            cout << endl;
        } else cout << "NO" << endl;
    }
}