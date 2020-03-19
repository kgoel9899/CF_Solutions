#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n, -1);
    vector<int> np(n, -1);
    int check[n + 1];
    for(int i=0;i<n;i++) {
        cin >> p[i];
        np[i] = p[i];
        check[i] = 0;
    }
    check[n] = 0;
    ll summ = 0, ans = 1;
    sort(np.begin(), np.end());
    for(int i=n-1;i>n-1-k;i--) {
        check[np[i]] = 1;
        summ += np[i];
    }
    vector<int> ind;
    for(int i=0;i<n;i++) {
        if(check[p[i]] == 1) {
            ind.push_back(i);
        }
    }
    for(int i=1;i<ind.size();i++) {
        ans = ((ans % MOD) * ((ind[i] - ind[i - 1]) % MOD)) % MOD;
    }
    cout << summ << " " << ans % MOD << endl;
}