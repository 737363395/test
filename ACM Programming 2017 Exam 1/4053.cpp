#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
bool p[32];
bool f[20];
int a[20];
int n, m = 0;
 
void solve(int x) {
	if (x == n) {
		for (int i = 2; i <= n; ++i)
			if (f[i] && p[i + 1] && p[i + a[x - 1]]) {
				a[x] = i;
				++m;
				for (int j = 1; j <= n; ++j) printf("%d ", a[j]);
				printf("\n");
			}
	} else {
		for (int i = 2; i <= n; ++i)
			if (f[i] && p[i + a[x - 1]]) {
				a[x] = i;
				f[i] = false;
				solve(x + 1);
				f[i] = true;
			}
	}
}
 
int main() {
	scanf("%d", &n);
	memset(f, true, sizeof(f));
	memset(p, false, sizeof(p));
	p[2] = p[3] = p[5] = p[7] = p[11] = p[13] = p[17] = p[19] = p[23] = p[29] = p[31] = true;
	a[1] = 1;
	f[1] = false;
	solve(2);
	if (!m) printf("None\n");
	return 0;
}
