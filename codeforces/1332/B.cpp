#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 40
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> primes(MAX, 1);
    primes[0] = 0;
    primes[1] = 0;
    vector<int> ans;
    for(int i=2;i*i<MAX;i++) {
        if(primes[i] == 1) {
            for(int j=i*i;j<MAX;j+=i) {
                primes[j] = 0;
            }
            
        }
    }
    for(int i=0;i<MAX;i++) {
        if(primes[i] == 1) ans.push_back(i);
    }
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<int> ret(n, -1);
        vector<int> ind(ans.size(), -1);
        int curr = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<ans.size();j++) {
                if(v[i] % ans[j] == 0) {
                    if(ind[j] != -1) ret[i] = ind[j];
                    else {
                        curr++;
                        ind[j] = curr;
                        ret[i] = curr;
                    }
                    break;
                }
            }
        }
        cout << curr << endl;
        for(int i=0;i<n;i++) {
            cout << ret[i] << " ";
        }
        cout << endl;
    }
}