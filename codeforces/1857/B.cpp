#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        bool ok=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]>='5')
            {
                ok=1;
                int pos=i;
                while(pos)
                {
                    s[pos-1]++;
                    if(s[pos-1]<'5') break;
                    --pos;
                }
                if(pos==0)
                {
                    cout<<'1';for(int i=0;i<s.size();++i) cout<<'0'; cout<<'\n';
                    break;
                }
                else
                {
                    for(int i=pos;i<s.size();++i) s[i]='0';
                    cout<<s<<'\n';break;
                }
            }
        }
        if(!ok) {cout<<s<<'\n';}
    }
    return 0;
}
