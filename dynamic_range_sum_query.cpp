/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-05.13:51:26
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> tree;
void build(vector<int> &a,int v,int l,int r){
    if(l == r)
        tree[v] = a[l];
    else{
        int mid = (l+r)/2;
        build(a,2*v,l,mid);
        build(a,2*v+1,mid+1,r);
        tree[v] = tree[2*v] + tree[2*v+1];
    }
}
int range_sum(int v,int tl,int tr,int l,int r){
    if(l>r)
        return 0;
    if(l==tl and r==tr)
        return tree[v];
    int tm = (tl+tr)/2;
    return range_sum(2*v,tl,tm,l,min(tm,r))+range_sum(2*v+1,tm+1,tr,max(l,tm+1),r);
}
void update(int v,int tl,int tr,int idx,int val){
    if(tl == tr)
        tree[v] = val;
    else{
        int tm = (tl+tr)/2;
        if(idx<=tm)
            update(2*v,tl,tm,idx,val);
        else 
            update(2*v+1,tm+1,tr,idx,val);
        tree[v] = tree[2*v]+tree[2*v+1];
    }
}

int32_t main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x:a)
        cin >> x;
    tree.resize(4*n);
    build(a,1,0,n-1);
    while(q--){
        int x;
        cin >> x;
        if(x==1){
            int idx,val;
            cin >> idx >> val;
            idx--;
            update(1,0,n-1,idx,val);
        }else{
            int u,v;
            cin >> u >> v;
            u--,v--;
            cout << range_sum(1,0,n-1,u,v) << endl;
        }
    }
    return 0;
}