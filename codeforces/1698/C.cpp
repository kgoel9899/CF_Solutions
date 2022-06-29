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
        int pos = 0, neg = 0, zero = 0;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            if(v[i] > 0) pos++;
            else if(v[i] < 0) neg++;
            else zero++;
        }
        if(pos >= 3 || neg >= 3) {
            cout << "NO" << endl;
            continue;
        }
        if(pos == 2 && zero != 0) {
            cout << "NO" << endl;
            continue;
        }
        if(neg == 2 && zero != 0) {
            cout << "NO" << endl;
            continue;
        }
        vector<int> temp;
        for(auto i : v) {
            if(i != 0) temp.push_back(i);
        }
        zero = min(zero, 3ll);
        while(zero--) {
            temp.push_back(0);
        }
        sort(all(temp));
        set<int> s(all(temp));
        dbg(s);
        int sz = temp.size(), ok = 1;
        for(int i=0;i<sz;i++) {
            for(int j=i+1;j<sz;j++) {
                for(int k=j+1;k<sz;k++) {
                    if(s.find(temp[i] + temp[j] + temp[k]) == s.end()) ok = 0;
                }
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}