#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    int mx = INT_MIN;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(a[i]>=mx)
            mx = a[i];
        else ans+=(mx-a[i]);
    }
    cout << ans << endl;
    return 0;
}