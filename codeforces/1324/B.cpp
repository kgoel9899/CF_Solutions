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
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }
        int flag = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+2;j<n;j++) {
                if(arr[j] == arr[i]) {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) {
                break;
            }
        }
        if(flag == 0) {
            cout << "NO" << endl;
        }
    }
}