/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-06.10:42:34
***********************************************/
#include <bits/stdc++.h>
using namespace std;
vector<int> tree;
void build(int v,int l,int r){
    if(l==r)
        tree[v] = 1;
    else{
        int mid = (l+r)/2;
        build(2*v,l,mid);
        build(2*v+1,mid+1,r);
        tree[v] = tree[2*v]+tree[2*v+1];
    }
}
int query(int v,int tl,int tr,int l,int r){
    if(l>r)
        return 0;
    if(l==tl and r==tr)
        return tree[v];
    int tm = (tl+tr)/2;
    return query(2*v,tl,tm,l,min(tm,r)) + query(2*v+1,tm+1,tr,max(tm+1,l),r);
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
int get(int x,int n){
    int l=0,r=n-1;
    int ans = -1;
    while(l<=r){
        int mid = (l+r)/2;
        int pref = query(1,0,n-1,0,mid);
        if(pref==x){
            ans = mid;
            r = mid-1;
        }else if(pref<x)
            l = mid+1;
        else 
            r = mid-1;
    }

    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n),q(n);
    for(int &x:a)
        cin >> x;
    tree.resize(4*n);
    build(1,0,n-1);
    for(int &x:q)
        cin >> x;
    for(int x:q){
        int idx = get(x,n);
        cout << a[idx] << " ";
        update(1,0,n-1,idx,0);
    }
    cout << endl;
    return 0;
}