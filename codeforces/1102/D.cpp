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
        string s;
        cin >> s;
        int z = 0, o = 0, t = 0;
        for(auto& i : s) {
            if(i == '0') z++;
            else if(i == '1') o++;
            else t++;
        }
        for(auto& i : s) {
            if(i == '0') continue;
            if(i == '1') {
                if(o > n / 3 && z < n / 3) {
                    i = '0';
                    o--;
                    z++;
                }
                continue;
            }
            if(t > n / 3 && z < n / 3) {
                i = '0';
                t--;
                z++;
            } else if(t > n / 3 && o < n / 3) {
                i = '1';
                t--;
                o++;
            }
        }
        dbg(s);
        for(int i=n-1;i>=0;i--) {
            if(s[i] == '2') continue;
            if(s[i] == '1') {
                if(o > n / 3 && t < n / 3) {
                    s[i] = '2';
                    t++;
                    o--;
                }
                continue;
            }
            if(z > n / 3 && t < n / 3) {
                s[i] = '2';
                t++;
                z--;
            } else if(z > n / 3 && o < n / 3) {
                s[i] = '1';
                o++;
                z--;
            }
        }
        cout << s << endl;
        // if(z == n / 3 && o == n / 3) {
        //     cout << s << endl;
        //     continue;
        // }
        // if(z == n / 3) {
        //     for(int i=n-1;i>=0&&o>n/3;i--) {
        //         if(s[i] == '1') {
        //             s[i] = '2';
        //             o--;
        //         }
        //     }
        //     for(int i=0;i<n&&t>n/3;i++) {
        //         if(s[i] == '2') {
        //             s[i] = '1';
        //             t--;
        //         }
        //     }
        // } else if(o == n / 3) {
        //     for(int i=n-1;i>=0&&z>n/3;i--) {
        //         if(s[i] == '0') {
        //             s[i] = '2';
        //             z--;
        //         }
        //     }
        //     for(int i=0;i<n&&t>n/3;i++) {
        //         if(s[i] == '2') {
        //             s[i] = '0';
        //             t--;
        //         }
        //     }
        // } else if(t == n / 3) {
        //     for(int i=n-1;i>=0&&z>n/3;i--) {
        //         if(s[i] == '0') {
        //             s[i] = '1';
        //             o--;
        //         }
        //     }
        //     for(int i=0;i<n&&o>n/3;i++) {
        //         if(s[i] == '1') {
        //             s[i] = '0';
        //             o--;
        //         }
        //     }
        // } else {

        //     cout << "here" << endl;
        //     continue;
        // }
        // cout << s << endl;
    }
}