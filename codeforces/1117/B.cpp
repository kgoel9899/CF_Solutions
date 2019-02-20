#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<unordered_set>
#include<bits/stdc++.h>
using namespace std;
int main() {
    long long int n, m, k;
    cin >> n >> m >> k;
    long long int arr[n];
    for(long long int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    long long int ans1 = (m / (k + 1)) * k * arr[0];
    long long int ans2 = (m / (k + 1)) * arr[1];
    long long int left = m - (m / (k + 1)) * k - (m / (k + 1));
    cout << ans1 + ans2 + left * arr[0] << endl;
}