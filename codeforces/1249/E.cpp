#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#define ll unsigned long long int
#define ld long double
#define MAX 8200
#define MOD 1000000007
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    int a[n], b[n];
    for(int i=1;i<n;i++) {
        cin >> a[i];
    }
    for(int i=1;i<n;i++) {
        cin >> b[i];
    }
    int dp[n + 1][2];
    dp[1][0] = 0;
    dp[1][1] = 0;
    dp[2][0] = a[1];
    dp[2][1] = b[1] + c;
    for(int i=3;i<=n;i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
        dp[i][1] = min(dp[i - 1][0] + c, dp[i - 1][1]) + b[i - 1];
    }
    for(int i=1;i<=n;i++) {
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
    cout << endl;
}