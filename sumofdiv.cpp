/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-31.00:09:13
***********************************************/
#include <bits/stdc++.h>
#define int long long
const int mod = 1e9+7;
using namespace std;
inline int add(int a,int b){ return (a+b)%mod;}
inline int mul(int a,int b){ return (a*b)%mod;}
int linear(int n){
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = add(ans,mul(i,n/i));
    }
    return ans;
}

signed main(){
    int n;
    cin >> n;
    cout << linear(n) << endl;
    return 0;
}