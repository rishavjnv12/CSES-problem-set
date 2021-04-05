
#include <bits/stdc++.h>
using namespace std;
/* WARSHAW DEBUGGING TEMPLATE (CREDIT:- ERRICHTO) */
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
	enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; ++it)
		*this << ", " + 2 * (it == d.b) << *it;
	ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
/***********************************************************/
template<typename T>void read(T &x){cin >> x;}
template<typename T,typename U>void read(T &x,U &y){cin >> x >> y;}
template<typename T>void read(vector<T>& a){for(T& x:a)cin >> x;}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
/***********************************************************/
bool check(vi &a,int mx){
	unordered_map<int,int> mp;
	for(int i=0;i<mx;i++)
		mp[a[i]]++;
	if(mp.size()==mx)
		return true;
	for(int i=mx;i<(int)a.size();i++){
		mp[a[i]]++;
		mp[a[i-mx]]--;
		if(mp[a[i-mx]]==0)
			mp.erase(a[i-mx]);
		if(mp.size()==mx)
			return true;
	}
	return false;
}
void solve(){
	int n;
 cin>>n;
 map<int,int>lastind;
 int a[n+1];
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
 }
 int i=1,ans=0;
 for(int j=1;j<=n;j++)
 {
  i=max(i,lastind[a[j]]+1);
  ans=max(ans,j-i+1);
  lastind[a[j]]=j;
 }

 cout<<ans<<endl;
}
int32_t main(){
	int t = 1;
	// read(t);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	for(int testcase = 0;testcase<t;testcase++){
			#ifdef F
					cout << testcase << ":";
			#endif
			solve();
	}
	return 0;
}