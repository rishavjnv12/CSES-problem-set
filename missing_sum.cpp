#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    sort(a.begin(),a.end());
    int res = 1;
    for(int i=0;i<n and a[i]<=res;i++)
        res += a[i];
    cout << res;
    return 0;
}


// 1,2,4,7