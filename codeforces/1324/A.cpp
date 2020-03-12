#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        int odd = 0, even = 0;
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            if(arr[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        if(even > 0 && odd > 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}