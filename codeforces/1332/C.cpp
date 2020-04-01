#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int tot = (n / k) * 2, ans = 0;
        for(int i=0;i<k/2;i++) {
            int ctr = 0, maxi = 0, j = i;
            unordered_map<char, int> hash;
            while(ctr < n) {
                hash[s[ctr + j]]++;
                hash[s[ctr + k - 1 - j]]++;
                maxi = max(maxi, max(hash[s[ctr + j]], hash[s[ctr + k - 1 - j]]));
                ctr += k;
            }
            ans += tot - maxi;
        }
        if(k % 2 == 1) {
            unordered_map<char, int> hash;
            int ctr = k / 2, maxi = 0;
            while(ctr < n) {
                hash[s[ctr]]++;
                maxi = max(maxi, hash[s[ctr]]);
                ctr += k;
            }
            ans += tot / 2 - maxi;
        }
        cout << ans << endl;
    }
}