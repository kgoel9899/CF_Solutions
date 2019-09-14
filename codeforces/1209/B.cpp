#include<bits/stdc++.h>
#include<iostream>
#define ll long long
#define MAX 8200
#define MOD 1000000007
using namespace std;

struct node {
    int a;
    int b;
    char ch;
};

bool compare(node x, node y) {
    return x.b < y.b;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    node arr[n];
    int ct = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i].a >> arr[i].b;
        arr[i].ch = s[i];
        if(s[i] == '1') {
            ct++;
        }
    }
    int ans = -1;
    ans = max(ans, ct);
    sort(arr, arr + n, compare);
    int check[n];
    for(int i=0;i<n;i++) {
        check[i] = -1;
    }
    for(int i=1;i<100000;i++) {
        int temp = ct;
        for(int j=0;j<n;j++) {
            if(check[j] == -1) {
                if(arr[j].b <= i) {
                    check[j] = 1;
                    if(arr[j].ch == '1') {
                        arr[j].ch = '0';
                        temp--;
                    } else {
                        arr[j].ch = '1';
                        temp++;
                    }
                }
            } else {
                if((i - arr[j].b) % arr[j].a == 0) {
                    if(arr[j].ch == '1') {
                        arr[j].ch = '0';
                        temp--;
                    } else {
                        arr[j].ch = '1';
                        temp++;
                    }
                }
            }
        }
        ct = temp;
        ans = max(ans, temp);
    }
    cout << ans << endl;
}


