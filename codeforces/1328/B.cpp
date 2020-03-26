#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1000005
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s = "";
        if(k == 1) {
            for(int i=0;i<n-2;i++) {
                s += 'a';
            }
            s += "bb";
            cout << s << endl;
        } else {
            ll summ = 1;
            ll x = 2;
            while(summ < k) {
                summ += x;
                x++;
            }
            x--;
            summ -= x;
            s += 'b';
            ll temp = k - summ - 1;
            for(int i=0;i<x;i++) {
                if(temp == x - i - 1) {
                    s += 'b';
                } else {
                    s += 'a';
                }
            }
            int left = n - s.size();
            string te = "";
            for(int i=0;i<left;i++) {
                te += 'a';
            }
            s = te + s;
            cout << s << endl;
        }
    }
}