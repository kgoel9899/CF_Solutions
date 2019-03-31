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
    int n;
    cin >> n;
    int arr[n];
    int flag = 0, l1 = 0, l2 = 0;
    int arr1[200001], arr2[200001];
    for(int i=0;i<=200000;i++) {
        arr1[i] = -1;
        arr2[i] = -1;
    }
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        if(flag != 1) {
            if(arr1[arr[i]] == -1) {
                arr1[arr[i]] = 1;
                l1++;
            } else if(arr2[arr[i]] == -1) {
                arr2[arr[i]] = 1;
                l2++;
            } else {
                flag = 1;
            }
        }
    }
    if(flag == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << l1 << endl;
        for(int i=0;i<=200000;i++) {
            if(arr1[i] == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
        cout << l2 << endl;
        for(int i=200000;i>=0;i--) {
            if(arr2[i] == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}