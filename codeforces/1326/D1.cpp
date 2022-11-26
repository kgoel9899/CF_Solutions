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

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = '#' + s + '$';
    vector<int> v(n + 2);
    int l = 1, r = 1;
    for(int i=1;i<=n;i++) {
        v[i] = max(0ll, min(r - i, v[l + (r - i)]));
        while(s[i - v[i]] == s[i + v[i]]) {
            v[i]++;
        }
        if(i + v[i] >= r) {
            l = i - v[i];
            r = i + v[i];
        }
    }
    return vector<int>(v.begin() + 1, v.end() - 1);
}
vector<int> manacher(string s) {
    string ns = "";
    for(auto& i : s) {
        ns += "#";
        ns += i;
    }
    ns += '#';
    dbg(ns);
    return manacher_odd(ns);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r && s[l] == s[r]) {
            l++;
            r--;
        }
        string pref = s.substr(0, l);
        string suff = pref;
        reverse(all(suff));
        s = s.substr(l, n - 2 * l);
        dbg(s);
        vector<int> v1 = manacher_odd(s);
        vector<int> v2 = manacher(s);
        dbg(v1);
        n = s.size();
        int ind1 = 0, mx1 = 1;
        for(int i=0;i<n;i++) {
            int left = i - v1[i] + 1, right = i + v1[i] - 1;
            if(v1[i] > mx1 && (left == 0 || right == n - 1)) {
                mx1 = v1[i];
                ind1 = i;
            }
        }
        int len1 = 2 * mx1 - 1;
        dbg(v2);
        int ind2 = -1, mx2 = 0;
        for(int i=0;i<n;i++) {
            int temp = (v2[2 * i] - 1) / 2;
            int left = i - temp, right = i + temp - 1;
            if(temp > mx2 && (left == 0 || right == n - 1)) {
                mx2 = temp;
                ind2 = i;
            }
        }
        int len2 = 2 * mx2;
        dbg(len1, len2);
        dbg(ind1, ind2);
        if(len1 > len2) cout << pref + s.substr(ind1 - mx1 + 1, len1) + suff << endl;
        else cout << pref + s.substr(ind2 - mx2, len2) + suff << endl;
    }
}