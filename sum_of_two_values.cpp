/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-06.11:24:55
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    set<int> st;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(st.count(x-a[i])){
            int target = x-a[i];
            for(int j=0;j<i;j++){
                if(a[j]==target){
                    cout << j+1 << " " << i+1 << endl;
                    return 0;
                }
            }
        }else{
            st.insert(a[i]);
        }
    }
    puts("IMPOSSIBLE");
    return 0;
}