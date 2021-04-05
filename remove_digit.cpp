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
vector<int> memo;
set<int> get_digit(int n){
	set<int> st;
	auto s = to_string(n);
	for(char c:s)
		if(c-'0')
			st.insert(c-'0');
	
	return st;
}
int rec(int n){
	if(n<10)
		return 1;
	else if(memo[n]!=-1)
		return memo[n];
	auto dig = get_digit(n);
	int ans = INT_MAX;
	for(int x:dig){
		ans = min(ans,rec(n-x));
	}
	return memo[n] = 1+ans;
}
int fun(int n){
	vector<int> dp(n+1,1e9);
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		for(char c:to_string(i))
			dp[i] = min(dp[i],dp[i-c+'0']+1);
	}
	return dp[n];
}
void solve(){
	int n;read(n);
	memo = vi(n+1,-1);
	// cout << rec(n) << "\n";
	cout << fun(n) << "\n";
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