#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 200010
using namespace std;

ll m, d;
string a, b;
ll n;
ll arra[2001], arrb[2001];
ll dp[2001][2001][2];
ll solve(ll arr[], int index, int rem, int small) {
    if(index > n) {
        if(rem == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if(dp[index][rem][small] != -1) {
        return dp[index][rem][small];
    }
    ll limit = -1;
    ll nsmall;
    if(small == 0) {
        limit = arr[index];
    } else {
        limit = 9;
    }
    ll res = 0;
    if(index % 2 == 0) {
        if(small == 1 || arr[index] >= d) {
            res = (res + (solve(arr, index + 1, (rem * 10 + d) % m, small || (d < arr[index]))) % MOD) % MOD;
        }
    } else {
        int add;
        if(index > 1) {
            add = 0;
        } else {
            add = 1;
        }
        for(int i=0+add;i<=limit;i++) {
            if(i == d) {
                continue;
            }
            if(i < arr[index]) {
                nsmall = 1;
            } else {
                nsmall = small;
            }
            res = (res + (solve(arr, index + 1, (rem * 10 + i) % m, nsmall)) % MOD) % MOD;
        }
    }
    dp[index][rem][small] = res;
    return res;
}
int main() {
    fast;
    cin >> m >> d;
    cin >> a >> b;
    for(int i=0;i<2001;i++) {
        for(int j=0;j<2001;j++) {
            for(int k=0;k<2;k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    n = (ll)a.size();
    for(int i=1;i<=n;i++) {
        arra[i] = a[i - 1] - '0';
        arrb[i] = b[i - 1] - '0';
    }
    ll ans1 = solve(arrb, 1, 0, 0);
    for(int i=0;i<2001;i++) {
        for(int j=0;j<2001;j++) {
            for(int k=0;k<2;k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    ll ans2 = solve(arra, 1, 0, 0);
    int i = 1;
    int rem = 0;
    for(;i<=n;i++) {
        if(i % 2 == 0) {
            if(arra[i] != d) {
                break;
            }
        } else {
            if(arra[i] == d) {
                break;
            }
        }
        rem = ((rem * 10) + arra[i]) % m;
    }
    ll ans3 = (i > n && rem == 0);
    ll ans4 = (ans1 - ans2 + MOD) % MOD;
    cout << (ans4 + ans3) % MOD << endl;
}