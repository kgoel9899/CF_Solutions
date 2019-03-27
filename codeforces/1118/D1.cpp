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
using namespace std;
bool check(int* arr, int days, int n, int m) {
    int checksum = 0, temp = 0;
    for(int i=0;i<n;i++) {
        checksum += max(0, arr[i] - temp);
        if((i + 1) % days == 0) {
            temp++;
        }
    }
    if(checksum >= m) {
        return true;
    }
    return false;
}
int main() {
    fast;
    int n, m;
    cin >> n >> m;
    int* arr = new int[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    int beg = 1, last = n, ans = n, flag = 0;
    while(beg <= last) {
        int mid = (last + beg) / 2;
        if(check(arr, mid, n, m) == true) {
            flag = 1;
            last = mid - 1;
            ans = min(ans, mid);
        } else {
            beg = mid + 1;
        }
    }
    if(flag == 1) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}