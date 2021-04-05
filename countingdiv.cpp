/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-30.20:07:15
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int ans = 0;
        for(int i=1;i*i<=n;i++){
            if(n%i == 0){
                if(i == n/i) ans++;
                else ans+=2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}