#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    cout << n << " ";
    if(n==1){
        cout << endl;
        return 0;
    }
    do{
        if(n&1)
            n = 3*n + 1;
        else n/=2;
        cout << n << " ";
    }while(n!=1);
    cout << "\n";
    return 0;

}