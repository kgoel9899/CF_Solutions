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
struct node {
    int value;
    int index;
    int color = -1;
};
bool compare1(node a, node b) {
    return a.value > b.value;
}
bool compare2(node a, node b) {
    return a.index < b.index;
}
int main() {
    int n, k;
    cin >> n >> k;
    node arr[n];
    int count[5001], flag = 0, check[k + 1];
    memset(count, 0, sizeof(int) * 5001);
    memset(check, 0, sizeof(int) * (k + 1));
    for(int i=0;i<n;i++) {
        cin >> arr[i].value;
        arr[i].index = i;
        count[arr[i].value] += 1;
    }
    sort(arr, arr + n, compare1);
    for(int i=0;i<5001;i++) {
        if(count[i] > k) {
            cout << "NO" << endl;
            flag = 1;
            break;
        }
    }
    if(flag != 1) {
        cout << "YES" << endl;
        int ktemp = 1;
        for(int i=0;i<n;i++) {
            if(ktemp > k) {
                ktemp = 1;
            }
            arr[i].color = ktemp;
            ktemp++;
        }
        sort(arr, arr + n, compare2);
        for(int i=0;i<n;i++) {
            cout << arr[i].color << " ";
        }
        cout << endl;
    }
}