/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-05.22:32:21
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> tree;

void build(vector<int> &a,int v,int l,int r){
    if(l==r)
        tree[v] = a[l];
    else{
        int mid = (l+r)/2;
        build(a,2*v,l,mid);
        build(a,2*v+1,mid+1,r);
        tree[v] = 0;
    }
}
void update(int v,int tl,int tr,int l,int r,int val){
    if(l>r)
        return;
    if(l==tl and r==tr)
        tree[v] += val;
    else{
        int tm = (tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm),val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,val);
    }
}
int point_query(int v,int tl,int tr,int pos){
    if(tl == tr)
        return tree[v];
    int tm = (tl+tr)/2;
    if(pos<=tm)
        return tree[v] + point_query(2*v,tl,tm,pos);
    else 
        return tree[v] + point_query(2*v+1,tm+1,tr,pos);
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
            int a,b,u;
            cin >> a >> b >> u;
            a--,b--;
            update(1,0,n-1,a,b,u);
        }else{
            int idx;
            cin >> idx;
            idx--;
            cout << point_query(1,0,n-1,idx) << endl;
        }

    }
    return 0;
}