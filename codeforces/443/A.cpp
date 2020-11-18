#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int cost;
bool check(vector<int>& b, vector<int>& p, int n, int m, int a, int mid) {
    cost = 0;
    for(int i=mid-1;i>=0;i--) {
        cost += p[mid - 1 - i];
        if(b[i] < p[mid - 1 - i]) a -= p[mid - 1 - i] - b[i];
    }
    return a >= 0;
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        string s;
        getline(cin, s);
        int n = s.size();
        set<char> st;
        for(int i=1;i<n-1;i+=3) {
            st.insert(s[i]);
        }
        cout << st.size() << endl;
    }
}