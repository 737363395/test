#include <cstdlib>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
long long f, t, t0, a1, t1, p1, a2, t2, p2;
 
int main() {
	long long ans = 1e16;
	scanf("%lld%lld%lld", &f, &t, &t0);
	scanf("%lld%lld%lld", &a1, &t1, &p1);
	scanf("%lld%lld%lld", &a2, &t2, &p2);
	for (long long k1 = 0; k1 <= f / a1 + 1; ++k1) {
		long long l = 0, r = (f - k1 * a1) / a2 + 1;
		while (l < r) {
			long long mid = (l + r) >> 1, k0 = max(f - k1 * a1 - mid * a2, 0ll);
			if (k0 * t0 + a1 * k1 * t1 + a2 * mid * t2 <= t) r = mid;
			else l = mid + 1;
		}
		ans = min(ans, p1 * k1 + p2 * l);
	}
	if (ans <= 1e16) printf("%lld\n", ans);
	else printf("-1\n");
	return 0;
}
