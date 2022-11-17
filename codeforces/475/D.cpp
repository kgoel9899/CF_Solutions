// not my solution
// this is -> https://codeforces.com/contest/475/submission/178912775

#include<bits/stdc++.h>
/*
*
* Created By : Mostafa Mahmoud
*
*/
#define sareeeee3 ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
#define ll long long
#define F first
#define S second
const int N = 1e5 + 15;
const ll mod = 1e9 + 9;
#define deb(x) cout<<#x<<"="<<x<<"\n";
ll tbl[N][30];
ll LOG[N];


void build(ll n, ll *a) {
    for (int i = 0; i <n; ++i) {
        tbl[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <=n; ++j) {
        for (int i = 0; i + (1 << j)<=n; ++i) {
            tbl[i][j] = __gcd(tbl[i][j - 1], tbl[i + (1 << (j - 1))][j - 1]);
        }
    }
}


ll query(ll L, ll R) {
    if(R<L){
        swap(R,L);
    }
    ll lg=LOG[R-L+1];
    return __gcd(tbl[L][lg],tbl[R-((1<<(lg)))+1][lg]);
}

void result() {
    ll n{},q{};
    cin>>n;
    ll a[n];
    map<ll,ll>m;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    build(n,a);
    for (int i = 0; i < n; ++i) {
        ll r=i;
        while (r<n){
            ll GCD= query(i,r);
            ll st = r, ed = n - 1;
            while (st<=ed) {
                ll mid = (st + ed) / 2;
                if(query(i,mid)==GCD){
                    st=mid+1;
                }else{
                    ed=mid-1;
                }
            }
            m[GCD]+=ed-r+1;
            r=ed+1;
        }

    }
    cin>>q;
    while (q--){
        ll x{};
        cin>>x;
        cout<<m[x]<<"\n";
    }

}


int main() {
    sareeeee3
    LOG[1]=0;
    for (int i = 2; i <N; ++i) {
        LOG[i]=LOG[i/2]+1;
    }
    ll tt = 1;
//    cin >> tt;
    for (int i = 0; i < tt; i++) {
        result();
//        cout << "\n";
    }
}