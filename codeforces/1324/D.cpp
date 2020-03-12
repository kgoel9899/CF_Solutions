#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }
    int diff[n];
    for(int i=0;i<n;i++) {
        diff[i] = a[i] - b[i];
    }
    sort(diff, diff + n);
    int check = 0;
    for(;check<n;check++) {
        if(diff[check] > 0) {
            break;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++) {
        if(diff[i] >= 0) {
            if(diff[i] == 0) {
                ans += n - check;
            } else {
                ans += n - i - 1;
            }
            continue;
        }
        int beg = i + 1, end = n - 1, temp = -1;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(diff[mid] > abs(diff[i])) {
                temp = mid;
                end = mid - 1;
            } else if(diff[mid] < abs(diff[i])) {
                beg = mid + 1;
            } else {
                beg = mid + 1;
            }
        }
        if(temp != -1) 
            ans += n - temp;
    }
    cout << ans << endl;
}