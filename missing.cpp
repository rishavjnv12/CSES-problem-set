// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    int sum = 0, rsum = (n*(n+1))/2;
    for(int i=0;i<n-1;i++){
        int x = 0;
        cin >> x;
        sum+=x;
    }
    cout << rsum - sum << endl;
    return 0;
}

