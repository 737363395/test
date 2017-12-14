#include <cstdlib>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
const int N = 150150;
const int M = 666;
 
bool f[N];
int a[N], b[N], t[N];
bool c[M][M];
 
int main() {
	int n, m, s = 0, p = 0;;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) f[i] = false;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		if (!f[a[i]]) {
			f[a[i]] = true;
			++s;
		}
		if (!f[b[i]]) {
			f[b[i]] = true;
			++s;
		}
	}
	if (s >= 600) {
		printf("NO\n");
		return 0;
	}
	for (int i = 1; i <= s; ++i)
		for (int j = 1; j <= s; ++j) c[i][j] = false;
	for (int i = 1; i <= m; ++i) {
		if (f[a[i]]) {
			++p;
			t[a[i]] = p;
			f[a[i]] = false;
		}
		if (f[b[i]]) {
			++p;
			t[b[i]] = p;
			f[b[i]] = false;
		}
		c[t[a[i]]][t[b[i]]] = c[t[b[i]]][t[a[i]]] = true;
	}
	for (int i = 1; i <= s; ++i)
		for (int j = 1; j <= s; ++j)
			for (int k = 1; k <= s; ++k)
				if (i != j && i != k && j != k && c[i][j] && c[j][k] && !c[i][k]) {
					printf("NO\n");
					return 0;
				}
	printf("YES\n");
	return 0;
}
