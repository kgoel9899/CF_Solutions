#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
bool compare(pair<int, int> a, pair<int, int> b) {
    return (a.second - a.first) < (b.second - b.first);
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<pair<int, int>> ans;
        int last = -1;
        int fi = -1, end = -1;
        for(int i=0;i<n;i++) {
            if(s[i] == 'W') {
                if(fi == -1) fi = i;
                ans.push_back({last, i});
                last = i;
                end = i;
            }
        }
        if(ans.size() > 0) ans.erase(ans.begin());
        sort(ans.begin(), ans.end(), compare);
        for(auto i : ans) {
            for(int j=i.first+1;j<i.second&&k>0;j++,k--) {
                s[j] = 'W';
            }
        }
        for(int i=end+1;i<n&&k>0;i++,k--) {
            s[i] = 'W';
        }
        for(int i=fi-1;i>=0&&k>0;i--,k--) {
            s[i] = 'W';
        }
        int ct = 0, br = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == 'W') {
                if(br == 0) {
                    ct++;
                    br = 1;
                } else ct += 2;
            } else br = 0;
        }
        cout << ct << endl;
    }
}