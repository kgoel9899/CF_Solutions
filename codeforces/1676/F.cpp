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
    int t = 1;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        map<int, int> m;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            m[v[i]]++;
        }
        int l = 0, r = -1;
        vector<int> temp;
        for(auto i : m) {
            if(i.second < k) {
                if(temp.size() != 0) {
                    int curr = temp[0];
                    int tl = curr, tr = curr;
                    // dbg(temp);
                    for(int j=1;j<temp.size();j++) {
                        if(temp[j] != curr + 1) {
                            if(tr - tl > r - l) {
                                r = tr;
                                l = tl;
                            }
                            tl = temp[j];
                            tr = temp[j];
                        } else tr++;
                        curr = temp[j];
                    }
                    if(tr - tl > r - l) {
                        r = tr;
                        l = tl;
                    }
                }
                temp.clear();
            } else {
                temp.push_back(i.first);
            }
        }
        if(temp.size() != 0) {
            int curr = temp[0];
            int tl = curr, tr = curr;
            // dbg(temp);
            for(int j=1;j<temp.size();j++) {
                if(temp[j] != curr + 1) {
                    if(tr - tl > r - l) {
                        r = tr;
                        l = tl;
                    }
                    tl = temp[j];
                    tr = temp[j];
                } else tr++;
                curr = temp[j];
            }
            if(tr - tl > r - l) {
                r = tr;
                l = tl;
            }
        }
        if(l == 0) cout << -1 << endl;
        else cout << l << " " << r << endl;
    }
}