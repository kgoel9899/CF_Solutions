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
    long long d;
    cin >> n >> d;
    long long arr[n];
    int ct = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    for(int i=1;i<n;i++) {
        if(arr[i] - arr[i - 1] > 2 * d) {
            ct += 2;
        } else if(arr[i] - arr[i - 1] == 2 * d) {
            ct++;
        }
    }
    cout << ct + 2 << endl;
}
