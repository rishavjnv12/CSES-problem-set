/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-05.19:20:58
***********************************************/
#include <bits/stdc++.h>
#define int long long
const int mx = 10000;
using namespace std;
int lcm(int a,int b){
    return (a/__gcd(a,b))*b;
}

int get_range_lcm(vector<int> &a,int u,int v){
    int ans = 1;
    for(int i=u;i<=v;i++)
        ans = lcm(ans,a[i]);
    return ans;
}
vector<int> tree;
void build(vector<int> &a,int v,int l,int r){
    if(l==r){
        tree[v] = a[l];
    }else{
        int mid = (l+r)/2;
        build(a,2*v,l,mid);
        build(a,2*v+1,mid+1,r);
        tree[v] = lcm(tree[2*v],tree[2*v+1]);
    }
}

int range_lcm(int v,int tl,int tr,int l,int r){
    if(l>r)
        return 1;
    if(l==tl and r==tr)
        return tree[v];
    int tm = (tl+tr)/2;
    int llcm = range_lcm(2*v,tl,tm,l,min(tm,r));
    int rlcm = range_lcm(2*v+1,tm+1,tr,max(l,tm+1),r);
    return lcm(llcm,rlcm);
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
        tree[v] = lcm(tree[2*v],tree[2*v+1]);
    }
}
int32_t main(){
    int n = mx;
    vector<int> a(n);
    for(int &x:a)
        x = 1 + rand()%10;
    int q = mx;
    tree.resize(4*n);
    build(a,1,0,n-1);
    for(int i=0;i<q;i++){
        int u = rand()%n;
        int v = u + rand()%(n-u);
        assert(u>=0 and u<n);
        assert(v>=u and v<n);
        int brutans = get_range_lcm(a,u,v);
        int sgans = range_lcm(1,0,n-1,u,v);
        assert(brutans == sgans);
    }
    return 0;
}