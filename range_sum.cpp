/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-04.23:12:20
***********************************************/
#include <bits/stdc++.h>
#define int long long
const int MAX = 1000000;
int counter = 0;
using namespace std;
struct SegTree{
    int left,right;
    SegTree* lchild,*rchild;
    int sum;
    SegTree(vector<int> &a,int l,int r){
        printf("%lld\n",++counter);
        left = l;
        right = r;
        if(left == right){
            sum = a[left];
            lchild = rchild = nullptr;
        }else{
            int mid = (left+right)/2;
            lchild = new SegTree(a,left,mid);
            rchild = new SegTree(a,mid+1,right);
            recalc();
        }
    }
    void recalc(){
        if(left == right)
            return;
        else 
            sum = lchild->sum + rchild->sum;
    }
    void pointUpdate(int index,int value){
        if(left == right){
            sum = value;
            return;
        }
        if(index <= lchild->right)
            lchild->pointUpdate(index,value);
        else 
            rchild->pointUpdate(index,value);
        recalc();
    }
    int rangeSum(int l,int r){
        // entirely disjoint
        if(l>right or r<left)
            return 0;
        
        // entirely covers
        if(l<=left and r>=right)
            return sum;
        else
            return lchild->rangeSum(l,r) + rchild->rangeSum(l,r);
    }
};




int get_range_sum(vector<int> &a,int u,int v){
    int ans = 0;
    for(int i=u;i<=v;i++) ans += a[i];
    return ans;
}

int32_t main(){
    int n = MAX;
    vector<int> a(n);
    for(int &x:a)
        x = rand()%1000000;
    int q = rand()%1000;
    cout << "HERE\n";
    SegTree *sg = new SegTree(a,0,n-1);

    
    int upd = 1;
    for(int i=0;i<q;i++){
        int u = rand()%n;
        int v = u + rand()%(n-u);
        assert(u>=0 and u<n);
        assert(v>=u and v<n);
        if(upd){
            a[v] = 100000;
            sg->pointUpdate(v,100000);
        }else{
            int brutforce = get_range_sum(a,u,v);
            int segans = sg->rangeSum(u,v);
            // cout << segans << "\n";
            assert(brutforce == segans);
        }
        upd ^= 1;
    }
    delete sg;
    return 0;
}