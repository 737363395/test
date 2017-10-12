#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int main() {
	const int N = 500500;
	int n, m, l, r;
	int a[N];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	l = 1;
	r = N;
	while (l < r) {
		int mid = (l + r) >> 1, sum = 0;
		for (int i = 1; i <= n; ++i) sum += a[i] / mid + ((a[i] % mid) > 0);
		if (sum <= m) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", r);
	return 0;
}
