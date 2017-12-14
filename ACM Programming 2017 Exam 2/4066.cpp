#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
const int N = 100100;
 
bool t[N];
int p[N];
 
int gcd(int x, int y) {
	if (!y) return x;
	else return gcd(y, x % y);
}
 
int main() {
	int n;
	bool f[44][44];
	scanf("%d", &n);
	for (int i = 0; i <= 40; ++i)
		for (int j = 0; j <= 40; ++j) f[i][j] = false;
	f[0][0] = true;
	for (int i = 0; i <= 40; ++i)
		for (int j = 0; j <= 40; ++j)
			if (f[i][j]) {
				if (i + 1 <= 40 && j + 2 <= 40) f[i + 1][j + 2] = true;
				if (i + 2 <= 40 && j + 1 <= 40) f[i + 2][j + 1] = true;
			}
	for (int i = 1; i < N; ++i) t[i] = true;
	p[0] = 0;
	for (int i = 2; i < N; ++i) {
		if (t[i]) {
			for (int j = i << 1; j < N; j += i) t[j] = false;
			++p[0];
			p[p[0]] = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		int a, b;
		bool c = true;
		scanf("%d%d", &a, &b);
		if (a < b) swap(a, b);
		if (gcd(a, b) == 1 && (a > 1 || b > 1)) printf("No\n");
		else {
			for (int k = 1; k <= p[0]; ++k) {
				int u = 0, v = 0, w = p[k];
				if (a == 1 || b == 1) break;
				while (!(a % w)) {
					a /= w;
					++u;
				}
				while (!(b % w)) {
					b /= w;
					++v;
				}
				if (!f[u][v]) {
					c = false;
					break;
				}
			}
			if (c && a == 1 && b == 1) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
