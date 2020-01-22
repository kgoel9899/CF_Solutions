#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#define ll long long int
#define ld long double
#define MAX 8200
#define MOD 1000000000
using namespace std;

struct node {
    int x;
    int y;
};
bool compare(node a, node b) {
    if(a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        string ans = "";
        int n;
        cin >> n;
        node arr[n];
        for(int i=0;i<n;i++) {
            cin >> arr[i].x >> arr[i].y;
        }
        sort(arr, arr + n, compare);
        int currx = 0, curry = 0;
        int diffx = -1, diffy = -1;
        int flag = 0;
        for(int i=0;i<n;i++) {
            if(arr[i].y < curry) {
                cout << "NO" << endl;
                flag = 1;

                break;
            }
            diffx = arr[i].x - currx;
            diffy = arr[i].y - curry;
            currx = arr[i].x;
            curry = arr[i].y;
            while(diffx--) {
                ans += 'R';
            }
            while(diffy--) {
                ans += 'U';
            }
        }
        if(flag == 1) {
            continue;
        } else {
            cout << "YES" << endl;
            cout << ans << endl;
        }
    }
}