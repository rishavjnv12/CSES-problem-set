#include <bits/stdc++.h>
#define int long long
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
const int mod = 1e9+7;
template<typename T>void read(T &x){cin >> x;}
template<typename T,typename U>void read(T &x,U &y){cin >> x >> y;}
template<typename T>void read(vector<T>& a){for(T& x:a)cin >> x;}
int mul(int a,int b){return (a*b)%mod;}
int power(int a,int b){
	if(b==0)
		return 1;
	if(a==0)
		return 0;
	if(b&1)
		return mul(a,power(a,b-1));
	else{
		int temp = power(a,b/2);
		return mul(temp,temp);
	}
}
/***********************************************************/
void solve(){
	int x;
	read(x);
	cout << power(2LL,x);
}
int32_t main(){
	int t;
	// read(t);
	t = 1;
	for(int testcase = 0;testcase<t;testcase++){
		#ifdef F
			cout << testcase << ":";
		#endif
		solve();
	}
	return 0;
}