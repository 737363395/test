#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 400400;

struct data {
	int l, r, k, h, s;
};

data a[N];
int ans = 0;

bool operator < (data x, data y) {
	return (long long)x.h * y.k < (long long)x.k * y.h;
}

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

void build(int cur, int l, int r) {
	int mid;
	a[cur].l = l;
	a[cur].r = r;
	a[cur].h = a[cur].s = 0;
	a[cur].k = l;
	if (l == r) return;
	mid = (l + r) >> 1;
	if (l <= mid) build(cur << 1, l, mid);
	if (mid < r) build(cur << 1 | 1, mid + 1, r);
}

int calc(int cur, data d) {
	int u, v;
	if (a[cur].l == a[cur].r) return d < a[cur];
	u = cur << 1;
	v = cur << 1 | 1;
	if (!(d < a[u])) return calc(v, d);
	else return a[cur].s - a[u].s + calc(u, d);
}

void modify(int cur, data d) {
	int mid, u, v;
	if (a[cur].l == a[cur].r) {
		a[cur].h = d.h;
		a[cur].s = 1;
		return;
	}
	mid = (a[cur].l + a[cur].r) >> 1;
	u = cur << 1;
	v = cur << 1 | 1;
	if (d.k <= mid) modify(u, d);
	if (d.k > mid) modify(v, d);
	if (a[u] < a[v]) {
		a[cur].k = a[v].k;
		a[cur].h = a[v].h;
	} else {
		a[cur].k = a[u].k;
		a[cur].h = a[u].h;
	}
	a[cur].s = a[u].s + calc(v, a[u]);
}

int main() {
	int t;
	t = read();
	while (t) {
		int n, m;
		n = read();
		m = read();
		build(1, 1, n);
		for (int i = 1; i <= m; ++i) {
			int h, k, p, ans;
			modify(1, (data){0, 0, read(), read(), 0});
			printf("%d\n", a[1].s);
		}
		--t;
	}
	return 0;
}
