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
        int arr[n], x = 1;
        map<int, int> m;
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            m[x] = arr[i];
            x++;
        }
        int ans[n] = {0};
        map<int, int>::iterator it = m.begin();
        for(int i=0;i<n;i++) {
            int fin = 1;
            if(it->second != it->first) {
                fin++;
            } 
            int reqd = i + 1;
            int curr = it->second;
            while(m[curr] != reqd) {
                curr = m[curr];
                fin++;
            }
            it++;
            ans[i] = fin;
        }
        for(int i=0;i<n;i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } 
}