#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 4 * 300010;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> v(N);
        int ind = 1;
        for(int i=0;i<n;i++) {
            int num;
            cin >> num;
            v[ind].push_back(num);
        }
        vector<int> ans;
        int ret = 0, ct = 1;
        for(int i=31;i>=0;i--) {
            int l = ct, r = ind;
            ct = ind + 1;
            int ansone = 0, anszero = 0;
            for(int j=l;j<=r;j++) {
                vector<int> ones, zeros;
                int invone = 0, invzero = 0;
                int sz = v[j].size();
                for(int k=sz-1;k>=0;k--) {
                    if(((v[j][k] >> i) & 1) == 1) {
                        anszero += invzero;
                        ones.push_back(v[j][k]);
                        invone++;
                    } else {
                        ansone += invone;
                        zeros.push_back(v[j][k]);
                        invzero++;
                    }
                }
                if(zeros.size() > 1) {
                    reverse(zeros.begin(), zeros.end());
                    v[ind + 1] = zeros;
                    ind++;
                }
                if(ones.size() > 1) {
                    reverse(ones.begin(), ones.end());
                    v[ind + 1] = ones;
                    ind++;
                }
            }
            ret += min(ansone, anszero);
            if(anszero <= ansone) ans.push_back(0);
            else ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());
        int num = 0, pw = 1;
        for(auto i : ans) {
            num += i * pw;
            pw *= 2;
        }
        cout << ret << " " << num << endl;
    }
}