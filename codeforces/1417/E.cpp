#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("-O3")
#define watch(x) cout << (#x) << " = " << (x) << endl
#define PI double(2 * acos(0.0))
#define LL long long
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define INF 1e15
vector<long long> v[8000000];

long long isithBitSet(long long n, long long k) 
{ 
    if (n & (1LL << (k))) 
        return 1; 
    else
        return 0; 
} 

vector<long long> tempOne;
vector<long long> tempZero;

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    long long x;
    long long index = -1;
    vector<long long> finalAns;
    for(long long i = 0; i < n; i++)    {
        cin >> x;
        v[index+1].push_back(x);
    }
    long long ans = 0;
    long long count = 0;
    for(long long i = 31; i >= 0; i--)  {
        long long temp = index+1;
        index = count;
        long long ansOne = 0;
        long long ansZero = 0;
        for(long long j = temp; j <= index; j++)    {
            long long len = v[j].size();
            long long one = 0;
            long long zero = 0;
            tempOne.clear();
            tempZero.clear();
            for(long long k = (len-1); k >= 0; k--) {
                if(isithBitSet(v[j][k], i)) {
                    ansZero += zero;
                    one++;
                    tempOne.push_back(v[j][k]);
                } else  {
                    ansOne += one;
                    zero++;
                    tempZero.push_back(v[j][k]);
                }   
            }
            if(tempOne.size() > 1)  {
                v[count+1] = tempOne;
                reverse(all(v[count+1]));
                count++;
            }
            if(tempZero.size() > 1) {
                v[count+1] = tempZero;
                reverse(all(v[count+1]));
                count++;
            }
        }
        ans += min(ansOne, ansZero);
        if(ansZero <= ansOne)   {
            finalAns.push_back(0);
        } else  {
            finalAns.push_back(1);
        }
    }
    cout << ans << " ";
    ans = 0;
    long long power2 = 1;
    reverse(all(finalAns));
    for(long long i = 0; i < (long long)finalAns.size(); i++)   {
        ans += finalAns[i]*power2;
        power2 *= 2;
    }
    cout << ans;
    return 0;
}
 