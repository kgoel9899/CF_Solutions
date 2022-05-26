#include <bits/stdc++.h>

using namespace std;

int query(int y)
{
    cout<<y<<"\n";
    fflush(stdout);
    int t;
    cin>>t;
    if(t==0||t==-2)
        exit(0);
    return t;
}

int main()
{
    int m,n;
    cin>>m>>n;
    int p[n];
    for(int i=0;i<n;i++)
    {
        int t=query(1);
        p[i]=t==1;
    }
    int l=2,r=m;
    for(int q=0;;q++)
    {
        int y=(l+r)/2;
        int t=query(y);
        if(!p[q%n])
            t*=-1;
        if(t==1)
            l=y+1;
        else
            r=y-1;
    }
}