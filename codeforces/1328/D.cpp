#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        int t[n];
        set<int> s;
        for(int i=0;i<n;i++) {
            cin >> t[i];
            s.insert(t[i]);
        }
        if(s.size() == 1) {
            cout << 1 << endl;
            for(int i=0;i<n;i++) {
                cout << 1 << " ";
            }
            cout << endl;
            continue;
        }
        if(n % 2 == 0) {
            int curr = 1;
            cout << 2 << endl;
            for(int i=0;i<n;i++) {
                cout << curr << " ";
                curr = 3 - curr;
            }
            cout << endl;
            continue;
        }
        int i = 0;
        for(;i<n;i++) {
            if(t[i] == t[(i + 1) % n]) {
                break;
            }
        }
        if(i < n) {
            int curr = 1;
            cout << 2 << endl;
            vector<int> ans(n, 0);
            for(int j=i+1;j<n;j++) {
                ans[j] = curr;
                curr = 3 - curr;
            }
            curr = 1;
            for(int j=i;j>=0;j--) {
                ans[j] = curr;
                curr = 3 - curr;
            }
            for(int i=0;i<n;i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        } else {
            int curr = 1;
            cout << 3 << endl;
            for(int i=0;i<n-1;i++) {
                cout << curr << " ";
                curr = 3 - curr;
            }
            cout << 3 << endl;
        }
    }
}