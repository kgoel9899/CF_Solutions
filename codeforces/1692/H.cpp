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
        int ans = 0;
        int a = -1, l = -1, r = -1;
        for(auto i : m) {
            if(ans == 0) {
                ans = 1;
                a = i.first;
                l = i.second[0] + 1;
                r = l;
            }
            int mx = 1;
            int currl = i.second[0] + 1, curry = i.second[0] + 1, ct = 1;
            for(int j=1;j<i.second.size();j++) {
                if(i.second[j] == i.second[j - 1] + 1) ct++;
                else {
                    int dist = i.second[j] - i.second[j - 1] - 1;
                    ct -= dist;
                    ct++;
                    if(ct <= 0) {
                        dbg(j);
                        ct = 1;
                        currl = i.second[j] + 1;
                        curry = i.second[j] + 1;
                    }
                }
                dbg(j, ct);
                if(ct > ans) {
                    ans = ct;
                    l = currl;
                    r = i.second[j] + 1;
                    a = i.first;
                }
            }
        }
        assert(l != -1);
        cout << a << " " << l << " " << r << endl;
    }
}