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
    int arr[n];
    int neww = -1;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        if(arr[i] % 2 == 0) {
            arr[i] /= 2;
        } else {
            if(neww == -1) {
                if(arr[i] >= 0) {
                    arr[i] /= 2;
                } else {
                    arr[i] /= 2;
                    arr[i]--;
                }
                neww = 1;
            } else {
                if(arr[i] >= 0) {
                    arr[i] /= 2;
                    arr[i]++;
                } else {
                    arr[i] /= 2;
                }
                neww = -1;
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout << arr[i] << endl;
    }
}