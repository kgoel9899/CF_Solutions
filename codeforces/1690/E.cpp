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
        sort(all(v));
        vector<vector<int>> rem(k);
        for(auto i : v) {
            rem[i % k].push_back(i);
        }
        int ans = 0;
        dbg(rem);
        for(int i=1;i<(k+1)/2;i++) {
            int x = rem[i].size(), y = rem[k - i].size();
            while(x > 0 && y > 0) {
                x--;
                y--;
                ans += (rem[i].back() + rem[k - i].back()) / k;
                rem[i].pop_back();
                rem[k - i].pop_back();
            }
        }
        if(k % 2 == 0) {
            int x = rem[k / 2].size();
            while(x >= 2) {
                x -= 2;
                int temp = rem[k / 2].back();
                rem[k / 2].pop_back();
                temp += rem[k / 2].back();
                rem[k / 2].pop_back();
                ans += temp / k;
            }
        }
        if(rem[0].size()) {
            int x = rem[0].size();
            while(x >= 2) {
                x -= 2;
                int temp = rem[0].back();
                rem[0].pop_back();
                temp += rem[0].back();
                rem[0].pop_back();
                ans += temp / k;
            }
        }
        dbg(rem);
        multiset<int> s;
        for(auto i : rem) {
            for(auto j : i) {
                ans += j / k;
                s.insert(j % k);
            }
        }
        dbg(s);
        while(s.size()) {
            int curr = *s.begin();
            s.erase(s.begin());
            int left = k - curr;
            auto it = s.lower_bound(left);
            dbg(curr, left, s);
            if(it == s.end()) continue;
            dbg(s);
            ans += (*it + curr) / k;
            s.erase(it);
        }
        cout << ans << endl;
    }
}

// 0, 2, 1, 1, 1, 2

// 2 + 7 = 9 -> 3
// 4 + 8 = 12 -> 4
// 3 + 1 = 4 -> 1