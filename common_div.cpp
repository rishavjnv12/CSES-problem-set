/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-30.20:13:51
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> st(1e6+1);
    int ans = 1;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                if(st.at(i)){
                    ans = max(ans,i);
                }
                if(st.at(x/i)){
                    ans = max(ans,x/i);
                }
                st.at(i) = 1;
                st.at(x/i) = 1;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}