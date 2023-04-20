#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, k;
string s;
set<char> st;

int32_t main()
{
    cin>>n>>k;
    cin>>s;
    for(auto it:s)
        st.insert(it);
    char first=*(st.begin());
    char last=*(--st.end());
    if(k>n)
    {
        cout<<s;
        for(int i=1;i<=k-n;i++)
        {
            cout<<*(st.begin());
        }
        return 0;
    }
    else
    {
        for(int i=k-1;i>=0;i--)
        {
            if(s[i]!=last)
            {
                s[i]=*(st.upper_bound(s[i]));
                break;
            }
            else
            {
                s[i]=first;
            }
        }
        cout<<s.substr(0, k);
    }
    return 0;
} 