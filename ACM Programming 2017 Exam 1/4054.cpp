#include <cstdlib>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
ll power(ll x, ll y) {
	if (!y) return 1;
	else {
		ll t = power(x, y >> 1);
		if (y & 1) return t * t * x;
		else return t * t;
	}
}
 
ll solve(ll x) {
	ll n = 0, m = x, ans = 9, l = x % 10, r;
	if (x < 10) return x % 10;
	while (m) {
		++n;
		if (m < 10) r = m;
		m /= 10;
	}
	for (int i = 2; i < n; ++i) ans += power(10, i - 2) * 9;
	ans += power(10, n - 2)	* (r - 1);
	ans += (x - power(10, n - 1) * r) / 10 + (l >= r);
	return ans;
}
 
int main() {
	ll l, r;
	scanf("%lld%lld", &l, &r);
	printf("%lld\n", solve(r) - solve(l - 1));
	return 0;
}
