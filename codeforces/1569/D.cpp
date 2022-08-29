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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> ver(n), hor(m);
        for(int i=0;i<n;i++) {
            cin >> ver[i];
        }
        for(int i=0;i<m;i++) {
            cin >> hor[i];
        }
        vector<int> x(k), y(k);
        vector<pair<int, int>> v(k);
        for(int i=0;i<k;i++) {
            cin >> x[i] >> y[i];
            v[i] = {x[i], y[i]};
        }
        sort(all(x));
        sort(all(y));
        dbg(x);
        dbg(y);
        int ans = 0;
        for(int i=1;i<n;i++) {
            int a = upper_bound(all(x), ver[i - 1]) - x.begin();
            int b = lower_bound(all(x), ver[i]) - x.begin();
            b--;
            if(a >= b) continue;
            int tot = b - a + 1;
            ans += (tot * (tot - 1)) / 2;
        }
        for(int i=1;i<m;i++) {
            int a = upper_bound(all(y), hor[i - 1]) - y.begin();
            int b = lower_bound(all(y), hor[i]) - y.begin();
            b--;
            if(a >= b) continue;
            int tot = b - a + 1;
            ans += (tot * (tot - 1)) / 2;
        }
        set<int> hors(all(hor));
        set<int> vers(all(ver));
        dbg(hors);
        dbg(vers);
        map<int, vector<int>> verm, horm;
        for(auto& i : v) {
            int a = i.first, b = i.second;
            if(vers.find(a) != vers.end() && hors.find(b) != hors.end()) continue;
            if(vers.find(a) != vers.end()) verm[a].push_back(b);
            if(hors.find(b) != hors.end()) horm[b].push_back(a);
        }
        for(auto& i : horm) {
            sort(all(i.second));
        }
        for(auto& i : verm) {
            sort(all(i.second));
        }
        dbg(horm);
        dbg(verm);
        for(auto& i : horm) {
            int ct = 0, last = -1;
            for(auto& j : i.second) {
                int ind = lower_bound(all(ver), j) - ver.begin();
                if(ind != last) {
                    ans -= (ct * (ct - 1)) / 2;
                    last = ind;
                    ct = 1;
                } else ct++;
            }
            ans -= (ct * (ct - 1)) / 2;
        }
        for(auto& i : verm) {
            int ct = 0, last = -1;
            for(auto& j : i.second) {
                int ind = lower_bound(all(hor), j) - hor.begin();
                if(ind != last) {
                    ans -= (ct * (ct - 1)) / 2;
                    last = ind;
                    ct = 1;
                } else ct++;
            }
            ans -= (ct * (ct - 1)) / 2;
        }
        cout << ans << endl;
    }
}