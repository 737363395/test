#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1000010;

ll f[N];
int c[N];

int main() {
	int t, n, a, b;
	ll s;
	scanf("%d", &t);
	while (t) {
		scanf("%d%d%d", &n, &a, &b);
		s = a + b;
		for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
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
