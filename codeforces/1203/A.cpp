#include<iostream>
#include<iomanip>
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
#define MAX 200010
using namespace std;
int main() {
    int q;
    cin >> q;
    while(q--) {
        int flag1 = 0, flag2 = 0;
        int n;
        cin >> n;
        int arr[n];
        int ind = -1;
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            if(arr[i] == 1) {
                ind = i;
            }
        }
        vector<int> v1, v2;
        for(int i=ind;i<n;i++) {
            v1.push_back(arr[i]);
        }
        for(int i=0;i<ind;i++) {
            v1.push_back(arr[i]);
        }
        for(int i=ind;i>=0;i--) {
            v2.push_back(arr[i]);
        }
        for(int i=n-1;i>ind;i--) {
            v2.push_back(arr[i]);
        }
        for(int i=0;i<n-1;i++) {
            if(v1[i + 1] < v1[i]) {
                flag1 = 1;
                break;
            }
        }
        for(int i=0;i<n-1;i++) {
            if(v2[i + 1] < v2[i]) {
                flag2 = 1;
                break;
            }
        }
        if(flag1 == 1 && flag2 == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}