#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int q;
        cin >> q;
        vector<vector<int>> v;
        vector<int> temp(26);
        temp[s[0] - 'a']++;
        v.push_back(temp);
        for(int i=1;i<n;i++) {
            temp[s[i] - 'a']++;
            v.push_back(temp);
        }
        while(q--) {
            string name;
            cin >> name;
            vector<int> check(26);
            for(int i=0;i<name.size();i++) {
                check[name[i] - 'a']++;
            }
            int beg = 0, end = n - 1;
            int ans = INT_MAX;
            while(beg <= end) {
                int mid = (beg + end) / 2;
                int flag = 0;
                for(int i=0;i<26;i++) {
                    if(check[i] > v[mid][i]) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    ans = min(ans, mid);
                    end = mid - 1;
                } else beg = mid + 1;
            }
            cout << ans + 1 << endl;
        }
    }
}