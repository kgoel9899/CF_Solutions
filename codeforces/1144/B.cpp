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
    int n;
    cin >> n;
    int arr[n];
    queue<int> q1, q2, temp1, temp2;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int even = 0, odd = 0;
    sort(arr, arr + n, greater<int>());
    ll summ = 0, sodd = 0, seven = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] % 2 == 0) {
            even++;
            seven += arr[i];
        } else {
            odd++;
            sodd += arr[i];
        }
        summ += arr[i];
    }
    sort(arr, arr + n, greater<int>());
    for(int i=0;i<n;i++) {
        if(arr[i] % 2 == 0) {
            q1.push(arr[i]);
        } else {
            q2.push(arr[i]);
        }
    }
    if(abs(even - odd) <= 1) {
        cout << 0 << endl;
    } else {
        if(even > odd) {
            summ -= sodd;
            for(int i=0;i<=odd;i++) {
                summ -= q1.front();
                q1.pop();
            }
        } else {
            summ -= seven;
            for(int i=0;i<=even;i++) {
                summ -= q2.front();
                q2.pop();
            }
        }
        cout << summ << endl;
    }
//    temp1 = q1;
//    temp2 = q2;
//    int curr;
//    if(arr[0] % 2 == 0) {
//        curr = 0;
//        q1.pop();
//    } else {
//        curr = 1;
//        q2.pop();
//    }
//    while(true) {
//        if(curr == 0 && q2.empty()) {
//            break;
//        }
//        if(curr == 1 && q1.empty()) {
//            break;
//        }
//        if(curr == 0) {
//            q2.pop();
//            curr = 1;
//        } else {
//            q1.pop();
//            curr = 0;
//        }
//    }
//    ll summ = 0;
//    while(!q1.empty()) {
//        summ += q1.front();
//        q1.pop();
//    }
//    while(!q2.empty()) {
//        summ += q2.front();
//        q2.pop();
//    }
//    cout << summ << endl;
}

//
//5 1


