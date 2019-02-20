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
    int n;
    cin >> n;
    int arr[n];
    int maxi = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        if(arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    int maxct = 0, ct = 0;
    int curr;
    for(int i=0;i<n;i++) {
        curr = arr[i];
        if(curr != maxi) {
            maxct = max(maxct, ct);
            ct = 0;
            continue;
        }
        ct++;
    }
    maxct = max(maxct, ct);
    cout << maxct << endl;
}