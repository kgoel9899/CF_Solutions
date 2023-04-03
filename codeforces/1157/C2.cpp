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
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        string ans = "";
        int l = 0, r = n - 1;
        int last = -1;
        while(l <= r) {
            int x = v[l], y = v[r];
            if(x == y) {
                int tx = l, ty = r;
                int left = 0, last_temp = last;
                while(tx <= ty) {
                    if(v[tx] > last) {
                        left++;
                        last = v[tx];
                        tx++;
                    } else break;
                }
                tx = l, ty = r, last = last_temp;
                int right = 0;
                while(tx <= ty) {
                    if(v[ty] > last) {
                        right++;
                        last = v[ty];
                        ty--;
                    } else break;
                }
                if(left >= right) ans += string(left, 'L');
                else ans += string(right, 'R');
                break;
            }
            int mn = min(x, y);
            int mx = max(x, y);
            if(last > mx) break;
            else if(last < mn) {
                if(x < y) {
                    last = x;
                    l++;
                    ans += "L";
                } else {
                    last = y;
                    r--;
                    ans += "R";
                }
            } else {
                if(x < y && y != last) {
                    last = y;
                    ans += "R";
                    r--;
                } else if(x > y && x != last) {
                    last = x;
                    ans += "L";
                    l++;
                } else break;
            }
        }
        cout << ans.size() << endl;
        cout << ans << endl;
    }
}