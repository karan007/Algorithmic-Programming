#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll r,c,i,j,a[100][100],row,col;
    row=col=0;
    cin>>r>>c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<r;i++)
    {
        if(a[i][0]==1)
        {
            col=1;
        }
    }
    for(i=0;i<c;i++)
    {
        if(a[0][i]==1)
        {
            row=1;
        }
    }
    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            if(a[i][j]==1)
            {
                a[0][j]=1;
                a[i][0]=1;
            }
        }
    }
    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            if(a[i][0]||a[0][j])
            {
                a[i][j]=1;
            }
        }
    }
    if(row)
    {
        for(i=0;i<c;i++)
        {
            a[0][i]=1;
        }
    }
    if(col)
    {
        for(i=0;i<r;i++)
        {
            a[i][0]=1;
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}