//https://lightoj.com/problem/crazy-calendar
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
#define LLONG_MAX 1e16
const ll M =1e9+7;
const ll N =2e5+1;
ll n,m;
int32_t main()
{
    fast
    ll i,j,k,p,q,tc=1,cs=0;cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        ll ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>k;
                if((n+m-2-i-j)&1) //Only counting when the number of move is negative.
                {
                    ans^=k;
                }
            }
        }
        cout<<"Case "<<++cs<<": "<<(ans?"win":"lose")<<endl;
    }
}
/**
This is another version of staircase nim.
If a coin can be moved even number of times, 
then the effect of moving that coin can be dismissed.
**/
