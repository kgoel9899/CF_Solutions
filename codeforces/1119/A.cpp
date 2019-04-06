#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<unordered_set>
#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1010
using namespace std;
int main() {
    fast;
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int maxi = INT_MIN;
    for(int i=n-1;i>=0;i--) {
        if(arr[i] != arr[0]) {
            maxi = i;
            break;
        }
    }
    for(int i=0;i<n;i++) {
        if(arr[i] != arr[n - 1]) {
            maxi = max(maxi, n - 1 - i);
            break;
        }
    }
    cout << maxi << endl;
}