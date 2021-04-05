// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    set<int> st;
    while(n--){
        int x;
        cin >> x;
        st.insert(x);
    }
    cout << st.size() << endl;
    return 0;
}

