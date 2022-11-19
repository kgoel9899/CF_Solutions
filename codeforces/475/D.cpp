#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
// #define int long long
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

const int N = 1e5 + 5;
const int LOG = 18;
int sparse[N][LOG];
int v[N];
int query(int l, int r) {
    int len = r - l + 1;
    int lg = log2(len);
    return __gcd(sparse[l][lg], sparse[r - (1 << lg) + 1][lg]);
}
int binsearch(int start, int lo, int hi, int shouldbe)
{
    int ans = lo;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(query(start, mid)==shouldbe)
        {
            lo=mid + 1;
            ans=mid;
        }
        else
            hi=mid-1;
    }
    return ans;
}

int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) {
            cin >> v[i];
            sparse[i][0] = v[i];
        }
        for(int j=1;j<LOG;j++) {
            for(int i=1;i+(1<<(j-1))-1<=n;i++) {
                sparse[i][j] = __gcd(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
            }
        }
        map<int, long long> m;
        for(int i=1;i<=n;i++)
        {
            int curgcd=v[i];
            int curlo=i;
            while(true)
            {
                int index=binsearch(i, curlo, n, curgcd);
                m[curgcd]+=(index-curlo+1);
                if(index==n)
                    break;
                curlo=index+1;
                curgcd=query(i, curlo);
            }
        }
        int q;
        cin >> q;
        while(q--) {
            int num;
            cin >> num;
            cout << m[num] << endl;
        }
    }
}