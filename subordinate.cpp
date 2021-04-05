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
vector<vector<int>> g;
vector<int> sub;
vector<bool> vis;
int dfs(int x){
	int ans = 0;
	vis[x] = true;
	for(int y:g[x]){
		if(vis[y]==false)
			ans += dfs(y);
	}
	sub[x] = ans;
	return ans+1;
}
void solve(){
	int n;
	read(n);
	g.resize(n+1);
	vis.resize(n+1,false);
	sub.resize(n+1);
	for(int i=2;i<=n;i++){
		int x;read(x);
		g[x].push_back(i);
	}
	debug() << imie(g);
	dfs(1);
	for(int i=1;i<=n;i++)
		cout << sub[i] << " ";
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