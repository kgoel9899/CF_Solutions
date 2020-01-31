#include<bits/stdc++.h>
#define ll long long int
#define MAX 8200
#define MOD 1000000000
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int dp[n];
    dp[0] = 1;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int maxi = 1;
    for(int i=1;i<n;i++) {
        if(arr[i] > arr[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
        maxi = max(maxi, dp[i]);
    }
    int right[n];
    right[n - 1] = 1;
    for(int i=n-2;i>=0;i--) {
        if(arr[i] < arr[i + 1]) {
            right[i] = right[i + 1] + 1;
        } else {
            right[i] = 1;
        }
    }
    for(int i=1;i<n-1;i++) {
        if(arr[i - 1] < arr[i + 1]) {
            maxi = max(maxi, dp[i - 1] + right[i + 1]);
        }
    }
    maxi = max(maxi, right[1]);
    maxi = max(maxi, dp[n - 2]);
    cout << maxi << endl;
}