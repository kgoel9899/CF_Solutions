#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds; 

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define f first
#define s second
#define sz(x) ll(x.size())
#define endl '\n'
#define forn(i,n) for(int i=0;i<n;++i)
#define fore(i,l,r) for(int i=int(l);i<=int(r);++i)
#define rep(i,begin,end) for(__typeof(end) i=(begin);i!=(end);i++)
#define fill(a,value) memset(a,value,sizeof(a));
#define gcd(a,b) __gcd((a),(b))
#define watch1(x) cout << (x) << endl
#define watch2(x,y) cout << (x) << " " << (y) << endl
#define watch3(x,y,z) cout << (x) << " " << (y) << " " << (z) << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
 
typedef long long ll;
typedef long double ld; 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> oset;

// find_by_order(k) returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

const int mod = 998244353;
const int inf = 9e18;
const int N = 1e5 + 5;

vi g[N];
int ans[N],dp[N];

void dfs(int v,int par){
    for(int u:g[v]){
        if(u!=par){
            dfs(u,v);
            dp[v]+=dp[u];
        }
    }
}

void solve(){
    int i,n;
    cin>>n;
    if(n==1){
        cout<<1;
        return;
    }
    for(i=2;i<=n;++i){
        int p;
        cin>>p;
        g[i].pb(p);
        g[p].pb(i);
    }
    for(i=2;i<=n;++i){
        dp[i]+=(sz(g[i])==1);
    }
    dfs(1,0);
    sort(dp+1,dp+1+n);
    for(i=1;i<=n;++i){
        cout<<dp[i]<<" ";
    }
}

signed main(){
    fastio;
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}