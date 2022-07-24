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

int n;
vector<pair<int, int>> v;
vector<vector<pair<int, int>>> fin;
map<int, vector<pair<int, int>>> m;
vector<vector<int>> dp;
int dist(pair<int, int>& p1, pair<int, int>& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int solve(int ind, int point) { // we are at square level ind and reached point (haven't travelled level ind yet)
    if(ind == (int)fin.size() - 1) return dist(fin[ind][0], fin[ind][1]);
    if(dp[ind][point] != -1) return dp[ind][point];
    int curr = dist(fin[ind][0], fin[ind][1]);
    if(point == 0) {
        // after travelling curr, we will be at point 1
        return dp[ind][point] = curr + min(dist(fin[ind][1], fin[ind + 1][0]) + solve(ind + 1, 0), dist(fin[ind][1], fin[ind + 1][1]) + solve(ind + 1, 1));
    } else {
        // after travelling curr, we will be at point 0
        return dp[ind][point] = curr + min(dist(fin[ind][0], fin[ind + 1][0]) + solve(ind + 1, 0), dist(fin[ind][0], fin[ind + 1][1]) + solve(ind + 1, 1));
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        v.clear();
        v.resize(n);
        m.clear();
        for(int i=0;i<n;i++) {
            cin >> v[i].first >> v[i].second;
            int mx = max(v[i].first, v[i].second);
            m[mx].push_back(v[i]);
        }
        for(auto& i : m) {
            vector<int> x, y;
            for(auto& j : i.second) {
                if(j.first == j.second) {
                    x.push_back(j.first);
                    y.push_back(j.first);
                    continue;
                }
                if(j.first == i.first) y.push_back(j.second);
                else if(j.second == i.first) x.push_back(j.first);
            }
            sort(all(x));
            sort(all(y));
            vector<pair<int, int>> temp;
            if(x.size()) {
                temp.push_back({x[0], i.first});
                temp.push_back({x.back(), i.first});
                if(y.size()) temp[1] = {i.first, y[0]};
            } else if(y.size()) {
                temp.push_back({i.first, y[0]});
                temp.push_back({i.first, y.back()});
            }
            i.second = temp;
        }
        dbg(m);
        fin.clear();
        fin.push_back({{0, 0}, {0, 0}});
        for(auto& i : m) {
            fin.push_back(i.second);
        }
        dbg(fin);
        dp.clear();
        dp.resize(fin.size() + 5, vector<int>(2, -1));
        int op1 = solve(0, 0);
        int op2 = solve(0, 1);
        dbg(op1, op2);
        cout << min(op1, op2) << endl;
    }
}