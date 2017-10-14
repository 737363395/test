#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1000010;

ll f[N];
int c[N];

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

int main() {
	int t, n, a, b;
	ll s;
	t = read();
	while (t) {
		n = read();
		a = read();
		b = read();
		s = a + b;
		for (int i = 1; i <= n; ++i) c[i] = read();
		for (int i = 1; i <= n; ++i) {
			s -= c[i];
			if (s < 0) {
				s += c[i];
				n = i - 1;
				break;
			}
		}
		s += c[n];
		f[n] = c[n];
		for (int i = n - 1; i; --i) {
			s += c[i];
			f[i] = min(f[i + 1] + c[i], s - f[i + 1] + 1);
		}
		printf(a >= f[1] ? "NanaBa\n" : "LuobeiHu\n");
		--t;
	}
	return 0;
}
