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
        string s;
        cin >> s;
        vector<int> freq(26);
        for(auto& i : s) {
            freq[i - 'a']++;
        }
        vector<pair<int, char>> v;
        for(char c='a';c<='z';c++) {
            v.push_back({freq[c - 'a'], c});
        }
        sort(all(v));
        reverse(all(v));
        int ans = INF, tot = INF;
        for(int i=1;i<=26;i++) {
            if(n % i) continue;
            // i want 'i' characters in the end
            int each = n / i;
            int good = 0;
            for(int j=0;j<i;j++) {
                good += min(each, v[j].first);
            }
            // dbg(i, each, good);
            if(n - good < ans) {
                ans = n - good;
                tot = i;
            }
        }
        // dbg(tot, ans);
        set<char> chars;
        for(int i=0;i<tot;i++) {
            chars.insert(v[i].second);
        }
        // dbg(chars);
        map<char, int> done;
        string fin = string(n, '#');
        for(int i=0;i<n;i++) {
            char c = s[i];
            if(chars.find(c) != chars.end()) {
                fin[i] = c;
                done[c]++;
                if(done[c] == n / tot) {
                    done.erase(c);
                    chars.erase(c);
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(fin[i] == '#') {
                assert(!chars.empty());;
                char c = *chars.begin();
                fin[i] = c;
                done[c]++;
                if(done[c] == n / tot) {
                    done.erase(c);
                    chars.erase(c);
                }
            }
        }
        cout << ans << endl;
        cout << fin << endl;
        // dbg(chars);
        // dbg(done);
    }
}