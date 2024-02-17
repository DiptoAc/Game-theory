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
vector<ll>dp(N,-1);
ll Grundy(ll x)
{
    if(dp[x]!=-1){return dp[x];}//If already calculated, then return;
    ll i;
    vector<ll>v(1000); //Once thing I learned here, initialization cost of vector is almost 1;
    for(i=1;i<(x+1)/2;i++) 
    {
        v[Grundy(x-i)^Grundy(i)]=1; //Take X-or of subgames
    }
    i=0;
    for(i=0;i<1000;i++){if(!v[i]){break;}} //Take mex of all possible states
    return dp[x]=i;
}
int32_t main()
{
    fast
    ll i,j,k,p,q,tc=1,cs=0;cin>>tc;
    dp[1]=0;
    dp[2]=0;
    while(tc--)
    {
        cin>>n;
        ll ans=0;
        vector<ll>v(n);
        for(auto &it:v)
        {
            cin>>it;
            ans^=Grundy(it);
        }
        cout<<"Case "<<++cs<<": "<<(ans?"Alice":"Bob")<<endl;
    }
}
/**
I am saving this problem, because this problem taught me that vector is much 
efficient for calculating mex
**/
