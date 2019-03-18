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
    int ans = 1, ans1 = 0;
    int* arr = new int[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i=0;i<n-1;i++) {
        int curr = arr[i], reqd = curr + 5, beg = i + 1, last = n - 1;
        while(beg <= last) {
            int mid = (beg + last) / 2;
            if(arr[mid] <= reqd) {
                beg = mid + 1;
                ans1 = mid - i + 1;
            } else if (arr[mid] > reqd) {
                last = mid - 1;
            }
        }
        ans = max(ans, ans1);
    }
    cout << ans << endl;
}