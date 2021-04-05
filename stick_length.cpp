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
	int n;read(n);
	vi a(n);
	read(a);
	vi suff(n),pref(n);
	sort(all(a));
	partial_sum(a.rbegin(),a.rend(),suff.rbegin());
	partial_sum(a.begin(),a.end(),pref.begin());
	debug() << imie(pref) imie(suff);
	int ans = LLONG_MAX;
	for(int i=0;i<n;i++){
		if(i==0){
			ans = min(ans,suff[i+1]-(n-1)*a[i]);
		}else if(i==n-1){
			int left = a[i]*i - pref[i-1];
			int right = 0;
			ans = min(ans,left+right);
		}else{
			int left = a[i]*i - pref[i-1];
			int right = suff[i+1] - a[i]*(n-1-i);
			// cout << i << " " << left << " " << right << endl;
			ans = min(ans,left+right);
		}
	}
	cout << ans;
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