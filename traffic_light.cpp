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
template<typename T>void read(T &x){cin >> x;}
template<typename T,typename U>void read(T &x,U &y){cin >> x >> y;}
template<typename T>void read(vector<T>& a){for(T& x:a)cin >> x;}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
/***********************************************************/
void solve(){
	int n,k;
	read(n,k);
	vi a(k);read(a);
	set<int> st;
	st.insert(0);
	st.insert(n+1);
	int ans = n;
	vector<int> res;
	int l = 0,r = n+1;
	for(int x:a){
		// auto it1 = lower_bound(all(st),x);
		// int left = *(--it1);
		// auto it2 = upper_bound(all(st),x);
		// int right = *it2;
		// ans = max(ans,right-left-1);
		// res.push_back(ans);
		if()
		st.insert(x);
	}
	for(int x:res)
		cout << x << " ";
	cout << "\n";
}
int32_t main(){
	int t = 1;
	// read(t);
	for(int testcase = 0;testcase<t;testcase++){
		#ifdef F
				cout << testcase << ":";
		#endif
		solve();
	}
	return 0;
}