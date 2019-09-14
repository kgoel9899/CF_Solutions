#include<bits/stdc++.h>
#include<iostream>
#define ll long long
#define MAX 8200
#define MOD 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int vis[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        vis[i] = 0;
    }
    int ct = 0;
    sort(arr, arr + n);
    for(int i=0;i<n;i++) {
        int curr = arr[i];
        if(vis[i] == 0) {
            ct++;
        }
        vis[i] = 1;
        for(int j=i+1;j<n;j++) {
            if(arr[j] % arr[i] == 0) {
                if(vis[j] == 0) {
                    vis[j] = 1;
                }
            }
        }
    }
    cout << ct << endl;
}