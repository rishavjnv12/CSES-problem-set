/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-05.13:51:26
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x:a)
        cin >> x;
    partial_sum(a.begin(),a.end(),a.begin());
    while(q--){
        int u,v;
        cin >> u >> v;
        u--,v--;
        cout << a[v] - (u?a[u-1]:0) << endl;
    }
    return 0;
}