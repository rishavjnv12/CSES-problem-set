#include <bits/stdc++.h>
#define P push_back
using namespace std;
using z=int;
vector<z> e[100001];
z d[100001],n,m,u,v;
z r(z &a,z &b){cin>>a>>b;}
z dfs(z c, z x)
{
    d[c]=x;
    for (z k : e[c])
    {
        if (!d[k])
            dfs(k,3-x);
        if (d[k]==d[c])
        {
            puts("IMPOSSIBLE");
            exit(0);
        }
    }
}
 
main()
{
    r(n,m);
    while (m--)
    {
        r(u,v);
        e[u].P(v);
        e[v].P(u);
    }
    queue<z> q;
    for(z i=1;i<=n;++i)
    {
        if (!d[i])
            dfs(i,1);
        cout<<d[i]<<" ";
    }
}