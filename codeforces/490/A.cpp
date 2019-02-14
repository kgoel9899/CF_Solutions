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
struct node{
    int num;
    int index;
};
bool compare(node a, node b) {
    return a.num > b.num;
}
int main() {
    int n;
    cin >> n;
    node arr[n];
    int c1 = 0, c2 = 0, c3 = 0;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        if(num == 1) {
            c1++;
        } else if (num == 2) {
            c2++;
        } else if (num == 3) {
            c3++;
        }
        arr[i].num = num;
        arr[i].index = i;
    }
    sort(arr, arr + n, compare);
    int reqd = min(c1, min(c2, c3));
    if(reqd == 0) {
        cout << 0 << endl;
    } else {
        cout << reqd << endl;
        int s1, s2, s3 = 0;
        int curr = 3;
        for(int i=1;i<n;i++) {
            if(curr != arr[i].num) {
                curr = arr[i].num;
                if(curr == 1) {
                    s1 = i;
                    break;
                } else {
                    s2 = i;
                }
            } else {
                continue;
            }
        }
        for(int i=0;i<reqd;i++) {
            cout << arr[s3].index + 1 << " " << arr[s2].index + 1 << " " << arr[s1].index + 1 << endl;
            s3++;
            s2++;
            s1++;
        }
    }
}