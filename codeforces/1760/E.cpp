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
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<int> suff(n);
        if(v[n - 1] == 0) suff[n - 1] = 1;
        for(int i=n-2;i>=0;i--) {
            suff[i] = suff[i + 1];
            if(v[i] == 0) suff[i]++;
        }
        int curr = 0;
        for(int i=0;i<n;i++) {
            if(v[i] == 1) curr += suff[i];
        }
        int ind = -1;
        for(int i=0;i<n;i++) {
            if(v[i] == 0) {
                v[i] = 1;
                ind = i;
                break;
            }
        }
        suff.clear();
        suff.resize(n);
        if(v[n - 1] == 0) suff[n - 1] = 1;
        for(int i=n-2;i>=0;i--) {
            suff[i] = suff[i + 1];
            if(v[i] == 0) suff[i]++;
        }
        int curr2 = 0;
        for(int i=0;i<n;i++) {
            if(v[i] == 1) curr2 += suff[i];
        }
        if(ind != -1) v[ind] = 0;
        for(int i=n-1;i>=0;i--) {
            if(v[i] == 1) {
                v[i] = 0;
                break;
            }
        }
        suff.clear();
        suff.resize(n);
        if(v[n - 1] == 0) suff[n - 1] = 1;
        for(int i=n-2;i>=0;i--) {
            suff[i] = suff[i + 1];
            if(v[i] == 0) suff[i]++;
        }
        int curr3 = 0;
        for(int i=0;i<n;i++) {
            if(v[i] == 1) curr3 += suff[i];
        }
        cout << max({curr, curr2, curr3}) << endl;
    }
}