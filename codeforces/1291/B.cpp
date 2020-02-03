#include<bits/stdc++.h>
#define ll long long int
#define MAX 8200
#define MOD 1000000000
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
        int i = 0;
        for(;i<n;i++) {
            if(arr[i] < i) {
                i--;
                break;
            }
        }
        int j = n - 1;
        for(;j>=0;j--) {
            if(arr[j] < n - 1 - j) {
                j++;
                break;
            }
        }
        if(i >= j) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}