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
    long long odd = 0, even = 0, tempodd = 0, tempeven = 0, total = 0, ansodd = 0, anseven = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        total += arr[i];
        if(i % 2 == 0) {
            odd += arr[i];
        } else {
            even += arr[i];
        }
    }
    int ct = 0;
    for(int i=0;i<n;i++) {
        if(i % 2 == 0) { // odd day
            ansodd = tempodd + even - tempeven;
            anseven = total - ansodd - arr[i];
            tempodd += arr[i];
        } else { // even day
            anseven = tempeven + odd - tempodd;
            ansodd = total - anseven - arr[i];
            tempeven += arr[i];
        }
        if(ansodd == anseven) {
            ct++;
        }
    }
    cout << ct << endl;
}