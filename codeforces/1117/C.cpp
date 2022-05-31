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

int x, y;
bool check(int x1, int y1, int x2, int y2, int n, int mid, string& s) {
    int tx = x * (mid / n);
    int ty = y * (mid / n);
    for(int i=0;i<mid%n;i++) {
        if(s[i] == 'U') ty++;
        else if(s[i] == 'D') ty--;
        else if(s[i] == 'L') tx--;
        else tx++;
    }
    x1 += tx;
    y1 += ty;
    return abs(x2 - x1) + abs(y2 - y1) <= mid;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n;
        cin >> n;
        string s;
        cin >> s;
        x = 0, y = 0;
        for(auto i : s) {
            if(i == 'U') y++;
            else if(i == 'D') y--;
            else if(i == 'L') x--;
            else x++;
        }
        int beg = 0, end = 1e15;
        int ans = -1;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(check(x1, y1, x2, y2, n, mid, s)) {
                ans = mid;
                end = mid - 1;
            } else beg = mid + 1;
        }
        cout << ans << endl;
    }
}