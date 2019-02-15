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
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int ans = arr[n - 1] - arr[0] + 1;
    if(k == 1) {
        cout << ans << endl;
    } else {
        k--;
        int diff[n - 1];
        for(int i=0;i<n-1;i++) {
            diff[i] = arr[i + 1] - arr[i] - 1;
        }
        sort(diff, diff + n - 1, greater<int>());
        for(int i=0;i<k;i++) {
            ans -= diff[i];
        }
        cout << ans << endl;
    }
}