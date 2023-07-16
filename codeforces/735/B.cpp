#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll     long long
#define test   int tt; cin>>tt; while(tt--)
#define ff     first
#define ss     second
#define pb     push_back
#define ppb    pop_back
#define pf     push_front
#define ppf    pop_front

template <typename T> using Ordered_Set_Tree =
        tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using Ordered_Multiset_Tree =
        tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

///DEBUG
void _Print(int t) {cerr << t;}
void _Print(string t) {cerr << t;}
void _Print(char t) {cerr << t;}
void _Print(long long t) {cerr << t;}
void _Print(double t) {cerr << t;}
void _Print(unsigned long long t) {cerr << t;}

template <class T, class V> void _Print(pair <T, V> &p);
template <class T> void _Print(vector <T> &v);
template <class T, class V> void _Print(T *v, V sz);
template <class T, class V, class P> void _Print(T *v, V sz, P sm);
template <class T> void _Print(set <T> &v);
template <class T, class V> void _Print(map <T, V> &v);
template <class T> void _Print(multiset <T> &v);

template <class T, class V> void _Print(pair <T, V> &p) {cerr << "{"; _Print(p.ff); cerr << ","; _Print(p.ss); cerr << "}\n\n";}
template <class T> void _Print(vector <T> &v) {cerr << "[ "; for (T i : v) {_Print(i); cerr << " ";} cerr << "]\n\n";}
template <class T, class V> void _Print(T *v, V sz) {cerr << "[ "; for(int i=0; i<sz; i++) {_Print(v[i]); cerr << " ";} cerr << "]\n\n";}
template <class T, class V, class P> void _Print(T *v, V sz, P sm) {cerr << "[\n"; for(int i=0; i<sz; i++) { for(int j=0; j<sm; j++) {_Print(v[i][j]); cerr << " ";} cerr << "\n";} cerr << "]\n\n";}
template <class T> void _Print(set <T> &v) {cerr << "[ "; for (T i : v) {_Print(i); cerr << " ";} cerr << "]\n\n";}
template <class T> void _Print(multiset <T>& v) {cerr << "[ "; for (T i : v) {_Print(i); cerr << " ";} cerr << "]\n\n";}
template <class T, class V> void _Print(map <T, V> &v) {cerr << "[ "; for (auto i : v) {_Print(i); cerr << " ";} cerr << "]\n\n";}
///DEBUG

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;
    cin>>n>>a>>b;

    int arr[n];
    for(auto &e: arr)
        cin>>e;

    sort(arr, arr+n);

    if(a<b)     swap(a, b);

    cout<<fixed<<setprecision(16);

    cout<<(accumulate(arr+n-b, arr+n, 0ll)*1.00)/b +
                    (accumulate(arr+n-b-a, arr+n-b, 0ll)*1.00)/a<<endl;
}
