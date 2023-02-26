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

bool check(string s, int l, int r) {
    for(int i=l;i<=r;i++) {
        if(s[i] == '1') s[i] = '0';
        else s[i] = '1';
    }
    dbg(s, l, r);
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
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
        int i = 0, j = n - 1;
        int diff = 0, x;
        while(i < j) {
            if(s[i] == s[j]) {
                if(diff) break;
                i++;
                j--;
                continue;
            }
            if(!diff) x = i;
            diff = 1;
            i++;
            j--;
        }
        if(i >= j && !diff) {
            cout << "Yes" << endl;
            continue;
        }
        assert(diff);
        if(i >= j) {
            if(check(s, x, (n - 1) / 2)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            if(check(s, x, i - 1)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}