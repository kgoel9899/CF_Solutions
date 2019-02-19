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
    long long odd = 0, even = 0, tempodd = 0, tempeven = 0, total = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        total += arr[i];
        if(i % 2 == 0) {
            odd += arr[i];
        } else {
            even += arr[i];
        }
    }
    long long tempodd1, tempeven1, ansodd = -1, anseven = -2;
    int ct = 0;
    for(int i=0;i<n;i++) {
        tempodd1 = odd;
        tempeven1 = even;
        if(i % 2 == 0) { // odd day
            ansodd = odd - tempodd1 + tempodd + tempeven1 - tempeven;
            anseven = total - ansodd - arr[i];
            tempodd += arr[i];
        } else { // even day
            anseven = even - tempeven1 + tempeven + tempodd1 - tempodd;
            ansodd = total - anseven - arr[i];
            tempeven += arr[i];
        }
        if(ansodd == anseven) {
            ct++;
        }
    }
    cout << ct << endl;
}