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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        k--;
        int i = k - 1, j = k + 1;
        int sum = v[k];
        while(true) {
            dbg("newwww");
            int temp1 = sum, mx1 = sum;
            int id = i, ind1 = i;
            while(id >= 0 && temp1 + v[id] >= 0) {
                temp1 += v[id];
                id--;
                if(temp1 >= mx1) {
                    mx1 = temp1;
                    ind1 = id;
                }
            }
            if(id < 0) {
                cout << "YES" << endl;
                break;
            }
            int temp2 = sum, mx2 = sum;
            int jd = j, ind2 = j;
            while(jd < n && temp2 + v[jd] >= 0) {
                temp2 += v[jd];
                jd++;
                if(temp2 >= mx2) {
                    mx2 = temp2;
                    ind2 = jd;
                }
            }
            if(jd >= n) {
                cout << "YES" << endl;
                break;
            }
            dbg(mx1, id);
            dbg(mx2, jd);
            if(mx1 == sum && mx2 == sum) {
                cout << "NO" << endl;
                break;
            }
            if(mx1 != sum && mx2 != sum) {
                if(mx1 > mx2) {
                    i = ind1;
                    sum = mx1;
                } else {
                    j = ind2;
                    sum = mx2;
                }
            } else if(mx1 != sum) {
                i = ind1;
                sum = mx1;
            } else {
                j = ind2;
                sum = mx2;
            }
        }
    }
}