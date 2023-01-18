#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ch() getchar()
#define pc(x) putchar(x)
using namespace std;
template<typename T>void read(T&x){
	static char c;static int f;
	for(f=1,c=ch();c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c>='0'&&c<='9';c=ch()){x=x*10+(c&15);}x*=f;
}
template<typename T>void write(T x){
	static char q[64];int cnt=0;
	if(x==0)return pc('0'),void();
	if(x<0)pc('-'),x=-x;
	while(x)q[cnt++]=x%10+'0',x/=10;
	while(cnt--)pc(q[cnt]);
}
const int maxn=200005;
int a[maxn];
int main(){
	int t;read(t);
	while(t--){
		int n;read(n);
		for(int i=1;i<=n;++i)
			read(a[i]);
		sort(a+1,a+n+1);
		if(a[1]==a[n]){
			write(n/2),pc('\n');
			continue;
		}
		long long ans=0;
		for(int l=1,r=1;l<=n;l=r=r+1){
			while(r+1<=n&&a[r+1]==a[l])++r;
			ans=max(ans,1ll*(n-r)*r);
		}
		write(ans),pc('\n');
	}
	return 0;
}