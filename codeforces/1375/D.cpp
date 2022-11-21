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
        vector<int> v(n), used(n + 1);
        for(int i=0;i<n;i++) {
            cin >> v[i];
            used[v[i]]++;
        }
        dbg(v);
        vector<int> ans;
        for(int i=0;i<n;i++) {
            int bad = -1;
            for(int j=0;j<n;j++) {
                if(v[j] != j) {
                    bad = j;
                    break;
                }
            }
            if(bad == -1) break;
            int mex = 0;
            for(int j=0;j<=n;j++) {
                if(used[j] == 0) {
                    mex = j;
                    break;
                }
            }
            dbg(i, mex);
            if(mex == n) {
                int ind = -1;
                for(int j=0;j<n;j++) {
                    if(v[j] != j) {
                        ind = j;
                        break;
                    }
                }
                used[v[ind]]--;
                v[ind] = mex;
                ans.push_back(ind + 1);
                used[v[ind]]++;
                for(int j=0;j<=n;j++) {
                    if(used[j] == 0) {
                        mex = j;
                        break;
                    }
                }
            }
            used[v[mex]]--;
            v[mex] = mex;
            used[v[mex]]++;
            ans.push_back(mex + 1);
        }
        dbg(v);
        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}