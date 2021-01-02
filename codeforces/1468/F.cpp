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

int32_t main()
{
    send help
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<ar<int,2>, int> m;
        for(int i=0;i<n;i++)
        {
            int a,b,x,y;
            cin>>a>>b>>x>>y;
            int dx=x-a;
            int dy=y-b;
            if(dx==0)
            {
                if(dy>0)
                    m[{inf,0}]++;
                else
                    m[{-inf,0}]++;
                continue;
            }
            if(dy==0)
            {
                if(dx>0)
                    m[{0,inf}]++;
                else
                    m[{0,-inf}]++;
                continue;
            }
            int g=abs(__gcd(dx,dy));
            dx/=g;
            dy/=g;
            // if(dx<0)
            // {
            //     dx*=-1;
            //     dy*=-1;
            // }
            m[{dy,dx}]++;
        }
        // for(auto x:m)
        //     cout<<x.first[0]<<" "<<x.first[1]<<" "<<x.second<<"\n";
        int ans=0;
        for(auto x:m)
        {
            if(x.first[0]==0)
            {
                if(m.find({0,-1*x.first[1]})!=m.end())
                    ans+=x.second*m[{0,-1*x.first[1]}];
                continue;
            }
            int f1=x.first[0];
            int f2=x.first[1];
            // if((f1<0 && f2<0) || (f1>0 && f2>0))
            {
                if(m.find({-f1,-f2})!=m.end())
                    ans+=x.second*m[{-f1,-f2}];
            }
        }
        cout<<ans/2<<"\n";
    }
}