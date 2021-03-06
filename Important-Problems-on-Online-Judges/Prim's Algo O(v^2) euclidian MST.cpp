// https://www.codechef.com/problems/CHEFGAME
// Euclidian Maximum Spanning tree By O(V^2) Prim's Algorithm
// You can use this implementation in case of complete graphs

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 6676;
#define mod 747474747
ll A[6676][10];
bool visited[MAX];
ll n,d;
ll dis(ll i,ll j)
{
    ll sum=0;
    for(ll k=1;k<=d;k++)
    {
        sum+=(A[i][k]-A[j][k])*(A[i][k]-A[j][k]);
    }
    return sum;
}
ll mx[6676];
long long prim(long long int x)
{
    long long maxScore=1LL;
    for(ll i=1;i<=n;i++)
    {
        visited[i]=false;
        mx[i]=0;
    }
    visited[1]=1;
    for(ll i=1;i<=n;i++)
    {
        if(visited[i])
            continue;
        mx[i]=max(mx[i],dis(1,i));
    }
    while(1)
    {
        ll mx1=0;
        ll ind=-1;
        for(ll i=1;i<=n;i++)
        {
            if(!visited[i]&&mx[i]>mx1)
            {
                mx1=mx[i];
                ind=i;
            }
        }
        if(mx1==0)
            break;
        maxScore=((maxScore%mod)*(mx1%mod))%mod;
        visited[ind]=true;
        for(ll i=1;i<=n;i++)
        {
            if(visited[i])
                continue;
            mx[i]=max(mx[i],dis(ind,i));
        }
    }
    return maxScore;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int t,x,maxScore,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=d;j++)
            {
                cin>>A[i][j];
            }
        }
        maxScore=prim(1);
        cout<<maxScore<<"\n";
    }
    return 0;
}
