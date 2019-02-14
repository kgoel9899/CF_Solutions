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
#define MAX 1000000
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    vector<int> v1, v2;
    v1.push_back(arr[0]);
    for(int i=1;i<n;i++) {
        if(arr[0] % arr[i] == 0) {
            if(find(v1.begin(), v1.end(), arr[i]) == v1.end()) {
                v1.push_back(arr[i]);
            } else {
                v2.push_back(arr[i]);
            }
        } else {
            v2.push_back(arr[i]);
        }
    }
//    sort(v1.begin(), v1.end(), greater<int>());
//    sort(v2.begin(), v2.end(), greater<int>());
    cout << arr[0] << " " << v2[0] << endl;
}
