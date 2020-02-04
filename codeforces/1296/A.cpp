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
        int odd = 0, summ = 0, even = 0;
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            summ += arr[i];
            if(arr[i] % 2 == 1) {
                odd = 1;
            } else {
                even = 1;
            }
        }
        if(summ % 2 == 1) {
            cout << "YES" << endl;
            continue;
        }
        if(odd == 0) {
            cout << "NO" << endl;
            continue;
        }
        if(odd == 1) {
            if(even == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            continue;
        }
    }
}