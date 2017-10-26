#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200200;

struct data {
	int u, v, w;
};

data a[N];
int f[N], s[N];
long long c[N];

bool comp(const data &x, const data &y) {
	return x.w > y.w;
}

int get(int x) {
	if (!f[x]) return x;
	else {
		f[x] = get(f[x]);
		return f[x];
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i < n; ++i) scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
		sort(a + 1, a + n, comp);
		for (int i = 1; i <= n; ++i) {
			c[i] = f[i] = 0;
			s[i] = 1;
		}
		for (int i = 1; i < n; ++i) {
			int x = get(a[i].u), y = get(a[i].v);
			long long p = c[x] + (long long) a[i].w * s[y], q = c[y] + (long long) a[i].w * s[x];
			if (p > q) {
				c[x] = p;
				f[y] = x;
				s[x] += s[y];
			} else {
				c[y] = q;
				f[x] = y;
				s[y] += s[x];
			}
		}
		printf("%lld\n", c[get(1)]);
		--t;
	}
	return 0;
}
