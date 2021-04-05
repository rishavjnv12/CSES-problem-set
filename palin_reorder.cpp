// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;


int32_t main(){
    string s;
    cin >> s;
    vector<int> mp(26);
    for(char ch:s)
        mp[ch-'A']++;
    int e = 0,o=0;
    for(int x:mp){
        if(x&1) o++;
        else e++;
    }
    if(o>=2)
        puts("NO SOLUTION");
    else{
        string pref = "",suff="";
        char odd = -1;
        for(int i=0;i<26;i++){
            if(mp[i]&1) odd = i;
            else{
                auto temp = string(mp[i]/2,i+'A');
                pref+=temp;
                suff = temp+suff;
            }
        }
        if(odd == -1){
            cout << pref + suff << endl;
        }else 
            cout << pref+string(mp[odd],'A'+odd)+suff << endl;
    }
    return 0;
}

