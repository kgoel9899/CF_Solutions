#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    int ct = 0;
    for(int i=0;i<n;i++) {
        cin >> b[i];
        if(b[i] == 1) {
            ct++;
        }
    }
    int nct = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == 1) {
            if(a[i] == b[i]) {
                ct--;
            } else {
                nct++;
            }
        }
    }
    if(nct == 0 && ct > 0) {
        cout << -1 << endl;
    } else if(nct == 0 && ct == 0){
        cout << -1 << endl;
    } else if(nct > 0 && ct == 0) {
        cout << 1 << endl;
    } else {
        cout << ceil((float)(ct + 1) / nct) << endl;
    }
}