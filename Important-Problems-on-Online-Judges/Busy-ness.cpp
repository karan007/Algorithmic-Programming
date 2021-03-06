// MST + Tree Problem
//https://www.codechef.com/problems/GOOGOL03
// Problem on Subtree Size and Number Of Paths With A node as intermediate node in the tree


#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll *id, cnt, *sz;
map<ll,ll> mp;  //use this map to map indexes with data.
void init(ll N)
{
    cnt = N;
	id = new ll[N+1];
	sz = new ll[N+1];
    for(ll i=1; i<=N; i++)
    {
        id[i] = i;
	    sz[i] = 1;
	}
}
ll find(ll p)
{
    if(id[p]==p)
        return p;
    return id[p]=find(id[p]);
}
// Replace sets containing x and y with their union.
void merge(ll x, ll y)
{
    ll i = find(x);
    ll j = find(y);
    if (i == j) return;
    // make smaller root point to larger one
    if(sz[i]<sz[j])
    {
        id[i]=j;
        sz[j]+=sz[i];
    }
    else
    {
        id[j]=i;
        sz[i]+=sz[j];
    }
    cnt--;
}
vector<pair <ll, pair<ll, ll> > > p;
vector<ll> mst[200003];
ll nodes,edges;
long long kruskal()
{
    ll x, y;
    long long cost, minimumCost = 0;
    for(ll i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(find(x) != find(y))
        {
            minimumCost += cost;
            mst[x].push_back(y);
            mst[y].push_back(x);
            merge(x, y);
        }
    }
    return minimumCost;
}
vector<pair<ll,ll> > v;
bool visited[200003];
ll subcnt[200003],ans[200003];
ll dfs(int x, int par)
{
    ans[x] = 0;
    subcnt[x] = 0;
    for (int i = 0; i < mst[x].size(); i++)
    {
        if (mst[x][i] == par)
            continue;
        ll ccnt = dfs(mst[x][i], x);
        ans[x] += ccnt * subcnt[x];
        subcnt[x] += ccnt;
    }
    return subcnt[x] + 1;
}
bool comp(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.first!=b.first)
    {
        return a.first>b.first;
    }
    return a.second<b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x, y;
    long long weight, cost, minimumCost;
    ll i,n;
    cin >> nodes >> edges;
    init(nodes);     //creating the sets
    for(i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p.push_back(make_pair(weight, make_pair(x, y)));
    }
    sort(p.begin(),p.end());
    minimumCost = kruskal();
    dfs(1,-1);
    for(i=1;i<=nodes;i++)
    {
        ans[i]+=subcnt[i]*(nodes-1-subcnt[i]);
        v.push_back(make_pair(-ans[i],i));
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
    {
        cout<<v[i].second<<"\n";
    }
    return 0;
}
