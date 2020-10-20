#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, vector<int>> m;
        for(int i=0;i<n;i++) {
            int num;
            cin >> num;
            m[num].push_back(i);
        }
        if(m.size() == 1) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            map<int, vector<int>>::iterator it = m.begin();
            int fi = it->second[0];
            it++;
            int se = it->second[0];
            while(it != m.end()) {
                vector<int> v = it->second;
                for(auto i : v) {
                    cout << fi + 1 << " " << i + 1 << endl;
                }
                it++;
            }
            it = m.begin();
            vector<int> v = it->second;
            for(int i=1;i<v.size();i++) {
                cout << se + 1 << " " << v[i] + 1 << endl;
            }
        }
    }
}