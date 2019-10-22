#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#define ll unsigned long long int
#define MAX 8200
#define MOD 1000000007
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int ct = 1;
        for(int i=1;i<n;i++) {
            if(arr[i] - arr[i - 1] == 1) {
                ct++;
                break;
            }
        }
        cout << ct << endl;
    }
}