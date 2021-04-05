/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-05.13:57:06
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> tree;
void build(vector<int> &a,int v,int left,int right){
    if(left==right)
        tree[v] = a[left];
    else{
        int mid = (left+right)/2;
        build(a,v*2,left,mid);
        build(a,v*2+1,mid+1,right);
        tree[v] = min(tree[v*2],tree[v*2+1]);
    }
}
int range_min(int v,int tl,int tr,int l,int r){
    if(l>r)
        return LLONG_MAX;
    if(l==tl and r==tr)
        return tree[v];
    int tm = (tl+tr)/2;
    int leftmin = range_min(2*v,tl,tm,l,min(r,tm));
    int rightmin = range_min(2*v+1,tm+1,tr,max(l,tm+1),r);
    return min(leftmin,rightmin);
}

int32_t main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x:a)
        cin >> x;
    tree.resize(4*n+1);
    build(a,1,0,n-1);
    while(q--){
        int u,v;
        cin >> u >> v;
        u--,v--;
        cout << range_min(1,0,n-1,u,v) << endl;
    }
    return 0;
}
