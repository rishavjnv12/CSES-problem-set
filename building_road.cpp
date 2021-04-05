#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> vis;
void dfs(int node){
    vis[node] = true;
    for(int x:g[node]){
        if(vis[x]==false)
            dfs(x);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    g.resize(n+1);
    vis.assign(n+1,false);
    while(m--){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size()-1 << "\n";
    for(int i=1;i<(int)ans.size();i++)
        cout << ans[i-1] << " " << ans[i] << "\n";
    return 0;
}