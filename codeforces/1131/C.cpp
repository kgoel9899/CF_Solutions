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
int main() {
    fast;
    ll n;
    cin >> n;
    ll arr[n], temp[n], j = 0;
    for(ll i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i=0;i<n;i+=2) {
        temp[j] = arr[i];
        j++;
    }
    if(n % 2 == 0) {
        for(ll i=1;i<n;i+=2) {
            temp[j] = arr[n - i];
            j++;
        }
    } else {
        for(ll i=1;i<n;i+=2) {
            temp[j] = arr[n - 1 - i];
            j++;
        }
    }
    for(int i=0;i<n;i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
}
