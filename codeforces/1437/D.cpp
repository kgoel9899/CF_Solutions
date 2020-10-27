    #include<bits/stdc++.h>
    using namespace std;
    #define MOD 1000000007
    #define int long long
    #define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define endl "\n"
    const int INF = 1e18;
    int32_t main() {
        int t = 1;
        cin >> t;
        while(t--) {
            int n;
            cin >> n;
            vector<int> v(n);
            for(int i=0;i<n;i++) {
                cin >> v[i];
            }
            vector<int> temp;
            temp.push_back(1);
            int ans = 1, prev = v[1], curr = 1;
            for(int i=2;i<n;i++) {
                if(v[i] > prev) {
                    curr++;
                    prev = v[i];
                } else {
                    int flag = 0;
                    temp[0]--;
                    if(temp[0] == 0) {
                        flag = 1;
                        temp.erase(temp.begin());
                        temp.push_back(curr);
                        curr = 1;
                    } else curr++;
                    prev = v[i];
                    if(flag == 1) ans++;
                }
            }
            cout << ans << endl;
        }
        return 0;
    }