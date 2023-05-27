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

bool good(int n, string& s) {
    int ct = 0;
    for(auto& i : s) {
        if(i == '(') ct++;
        else ct--;
        if(ct < 0) return false;
    }
    cout << 1 << endl;
    for(int i=0;i<n;i++) {
        cout << 1 << " ";
    }
    cout << endl;
    return true;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n % 2) {
            cout << -1 << endl;
            continue;
        }
        int op = 0;
        for(auto& i : s) {
            if(i == '(') op++;
        }
        if(op != n / 2) {
            cout << -1 << endl;
            continue;
        }
        if(good(n, s)) continue;
        reverse(all(s));
        if(good(n, s)) continue;        
        reverse(all(s));
        vector<int> ans(n, 1);
        int ct = 0, rev = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '(') ct++;
            else ct--;
            if(ct < 0 && s[i] == ')') {
                rev++;
                ans[i] = 2;
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(s[i] == '(' && rev) {
                rev--;
                ans[i] = 2;
            }
        }
        cout << 2 << endl;
        for(auto& i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}