#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e5 + 5, M = 1e5 + 5;

int n, m;
int mn[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 1 ; i <= n ; ++i)
            mn[i] = n;
    
        for(int i = 0 ; i < m ; ++i){
            int x, y;
            scanf("%d %d", &x, &y);
            
            if(x > y)
                swap(x, y);
                
            mn[x] = min(mn[x], y - 1);
        }
    
        for(int i = n - 1 ; i ; --i)
            mn[i] = min(mn[i], mn[i + 1]);
    
        ll ans = n;
        for(int i = 0 ; i < n ; ++i)
            ans += (mn[i] - i);
    
        printf("%lld\n", ans);
    }
}