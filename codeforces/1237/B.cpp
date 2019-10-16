#include<bits/stdc++.h>
#include<iostream>
#include<set>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
using namespace std;
int main() {
    int n;
    cin >> n;
    int st[n], end[n];
    for(int i=0;i<n;i++) {
        cin >> st[i];
    }
    for(int i=0;i<n;i++) {
        cin >> end[i];
    }
    map<int, int> m;
    int curr, neww;
    int l1 = 0, l2 = 0;
    int ct = 0;
    while(l1 < n) {
        curr = st[l1];
        neww = end[l2];
        if(curr == neww) {
            m[neww] = 1;
            l1++;
            l2++;
        } else {
            if(m[curr] != 1) {
                ct++;
                m[neww] = 1;
                l2++;
            } else {
                l1++;
            }
        }
    }
    cout << ct << endl;
}