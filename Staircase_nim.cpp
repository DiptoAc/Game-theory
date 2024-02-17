//http://poj.org/problem?id=1704
// This is the classic staircase nim.  (Hard for intution, but easy once solved)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

const ll M = 998244353;
const ll N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll tc;
    cin >> tc;

    while (tc--)
        {
            ll n,i;
            cin>>n;
            vector<ll>v(n+1),ans;

            ll x =0;
            for(i=1;i<=n;i++){cin>>v[i];}
            sort(v.begin(),v.end());
            for(i=n;i>=1;i--)
            {
                ans.push_back(v[i]-v[i-1]-1);
            }
            for(i=0;i<ans.size();i+=2)
            {
                x^=ans[i];
            }
            cout<<(!x?"Bob will win":"Georgia will win")<<endl;
        }
    return 0;
}
