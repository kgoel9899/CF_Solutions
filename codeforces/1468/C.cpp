#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mod 1000000007
#define inf 100000000000000000
#define ar array
#define send ios::sync_with_stdio(false);
#define help cin.tie(0);
#define setpres(x) fixed<<setprecision(x)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) { for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout<<"\n";}
template<typename A,typename B> ostream& operator<<(ostream &cout, map<A,B> const &v) { for(auto x:v) cout<<x.first<<": "<<x.second<<"\n";}
template<typename A> ostream& operator<<(ostream &cout, vector<ar<A,2>> const &v) { for(int i=0;i<v.size();i++) cout<<v[i][0]<<" "<<v[i][1]<<"\n";}

const int mxN=500004;
int a[mxN];
int timer;
struct comp
{
    bool operator()(const int &x, const int &y)
    {
        if(a[x]!=a[y])
            return a[x]>=a[y];
        return x<y;
    }
};
int32_t main()
{
    send help
    int q;
    cin>>q;
    map<int,int> m1;
    map<int,int,comp> m2;
    while(q--)
    {
        int no;
        cin>>no;
        if(no==1)
        {
            timer++;
            int money;
            cin>>money;
            a[timer]=money;
            m1.insert({timer,money});
            m2.insert({timer,money});
        }
        else if(no==2)
        {
            auto it=m1.begin();
            cout<<it->first<<" ";
            m1.erase(it);
            m2.erase(it->first);
        }
        else
        {
            auto it=m2.begin();
            cout<<it->first<<" ";
            m2.erase(it);
            m1.erase(it->first);
        }
    }
}