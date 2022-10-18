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
    const int N = 1e5 + 5;
    vector<int> prime(N, 1);
    for(int i=2;i*i<=N;i++) {
        if(prime[i]) {
            for(int j=i*i;j<N;j+=i) {
                prime[j] = 0;
            }
        }
    }
    while(tt--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int div = a * b;
        map<int, int> m;
        while(div % 2 == 0) {
            m[2]++;
            div /= 2;
        }
        for(int i=3;i*i<=div;i+=2) {
            int ct = 0;
            while(div % i == 0) {
                ct++;
                div /= i;
            }
            if(ct) m[i] = ct;
        }
        if(div > 2) m[div]++;
        // dbg(m, a * b);
        int ok = 0;
        for(int i=a+1;i<=c;i++) {
            map<int, int> m1;
            int temp = i;
            while(temp % 2 == 0) {
                m1[2]++;
                temp /= 2;
            }
            for(int j=3;j*j<=temp;j+=2) {
                int ct = 0;
                while(temp % j == 0) {
                    ct++;
                    temp /= j;
                }
                if(ct) m1[j] = ct;
            }
            if(temp > 2) m1[temp]++;
            int reqd = 1;
            for(auto j : m) {
                int num = j.first;
                int orig = j.second, curr = m1[num];
                int rem = max(0ll, orig - curr);
                while(rem > 0) {
                    reqd *= num;
                    rem--;
                }
            }
            // dbg(m1, i, reqd);
            int beg = 1, end = 1e5;
            int ans = -1;
            while(beg <= end) {
                int mid = (beg + end) / 2;
                int mult = reqd * mid;
                if(mult > d) end = mid - 1;
                else if(mult <= b) beg = mid + 1;
                else {
                    ans = mult;
                    break;
                }
            }
            if(ans != -1) {
                cout << i << " " << ans << endl;
                ok = 1;
                break;
            }
        }
        if(ok == 0) cout << -1 << " " << -1 << endl;
    }
}