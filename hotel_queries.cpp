/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-05.23:08:44
***********************************************/
#include <bits/stdc++.h>
using namespace std;
vector<int> tree;
void build(vector<int> &a,int v,int left,int right){
    if(left==right)
        tree[v] = a[left];
    else{
        int mid = (left+right)/2;
        build(a,v*2,left,mid);
        build(a,v*2+1,mid+1,right);
        tree[v] = max(tree[v*2],tree[v*2+1]);
    }
}
int range_max(int v,int tl,int tr,int l,int r){
    if(l>r)
        return INT_MIN;
    if(l==tl and r==tr)
        return tree[v];
    int tm = (tl+tr)/2;
    int leftmax = range_max(2*v,tl,tm,l,min(r,tm));
    int rightmax = range_max(2*v+1,tm+1,tr,max(l,tm+1),r);
    return max(leftmax,rightmax);
}
void update(int v,int tl,int tr,int idx,int val){
    if(tl == tr)
        tree[v] -= val;
    else{
        int tm = (tl+tr)/2;
        if(idx<=tm)
            update(2*v,tl,tm,idx,val);
        else 
            update(2*v+1,tm+1,tr,idx,val);
        tree[v] = max(tree[2*v],tree[2*v+1]);
    }
}
bool check(int n,int pos,int x){
    return range_max(1,0,n-1,1,pos) >= x;
}
int32_t main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> hotel(n);
    vector<int> tourist(m);
    for(int &x:hotel)
        scanf("%d",&x);
    for(int &x:tourist)
        scanf("%d",&x);
    tree.resize(4*n);
    build(hotel,1,0,n-1);
    for(int x:tourist){
        int l = 0,r = n-1;
        if(range_max(1,0,n-1,l,r)<x){
            printf("0 ");
            continue;
        }
        if(range_max(1,0,n-1,0,0)>=x){
            printf("1 ");
            update(1,0,n-1,0,x);
            continue;
        }
        int ans;
        while(l<=r){
            int mid = (l+r)/2;
            if(check(n,mid,x)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        printf("%d ",ans+1);
        update(1,0,n-1,ans,x);

    }
    printf("\n");
    return 0;
}
