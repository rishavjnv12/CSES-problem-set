#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << "1" << endl;
        return 0;
    }
    if(n==2 or n==3){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    vector<int> ans;
    int pt1 = (n+2)/2,pt2 = 1;
    int move = 1;
    while(ans.size()<n){
        if(move)
            ans.push_back(pt1++);
        else ans.push_back(pt2++);
        move ^= 1;
    }
    for(int x:ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
