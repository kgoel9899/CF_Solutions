#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string s = "";
    for(int i=0;i<k;i++) {
        int x, y;
        cin >> x >> y;
    }
    for(int i=0;i<k;i++) {
        int x, y;
        cin >> x >> y;
    }
    for(int i=1;i<m;i++) {
        s += 'L';
    }
    for(int i=1;i<n;i++) {
        s += 'U';
    }
    char c = 'L';
    for(int i=1;i<=n;i++) {
        c = c == 'L' ? 'R' : 'L';
        for(int j=1;j<m;j++) {
            s += c;
        }
        if(i != n) s += 'D';
    }
    cout << s.size() << endl;
    cout << s << endl;
}