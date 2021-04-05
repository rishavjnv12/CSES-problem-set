// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;

int32_t main(){
    string s;
    cin >> s;
    s+='*';
    int ans = 1;
    int curr = 1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1])
            curr++;
        else{
            ans = max(ans,curr);
            curr = 1;
        }
    }
    cout << ans << endl;
    return 0;
}

