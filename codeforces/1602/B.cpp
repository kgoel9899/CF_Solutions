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

bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
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
        int q;
        cin >> q;
        vector<vector<int>> ques(q, vector<int>(3));
        for(int i=0;i<q;i++) {
            cin >> ques[i][0] >> ques[i][1];
            ques[i][2] = i;
        }
        sort(all(ques), compare);
        int done = 0;
        // dbg(ques);
        vector<int> ans(q);
        for(auto& i : ques) {
            int step = i[1];
            while(done < step && done < n) {
                map<int, int> m;
                for(auto& j : v) {
                    m[j]++;
                }
                for(auto& j : v) {
                    j = m[j];
                }
                done++;
                // dbg(done, v);
            }
            ans[i[2]] = v[i[0] - 1];
        }
        for(auto& i : ans) {
            cout << i << endl;
        }
    }
}