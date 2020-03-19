#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int n;
    cin >> n;
    ll b[n];
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }
    cout << b[0] << " ";
    ll summ = b[0];
    for(int i=1;i<n;i++) {
        if(b[i] < 0) {
            cout << summ + b[i] << " ";
        } else {
            summ += b[i];
            cout << summ << " ";
        }
    }
    cout << endl;
}