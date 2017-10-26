#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t) {
		int n;
		long long a[55];
		bool f;
		long long ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		do {
			long long m = 0;
			f = true;
			for (int i = 1; i <= n; ++i)
				if (a[i] >= n) {
					f = false;
					m += a[i] / n;
				}
			for (int i = 1; i <= n; ++i)
				a[i] = a[i] % n + m - a[i] / n;
			ans += m;
		} while (!f);
		printf("%lld\n", ans);
		--t;
	}
}
