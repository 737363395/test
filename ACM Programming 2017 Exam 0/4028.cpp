#include <cstdlib>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
const int N = 1024;
const int M = 1001000;
	
bool a[N][N], b[N][N];
int x[M], y[M];
	
int main() {
	int t;
	scanf("%d", &t);
	while (t) {
		int n, m, p, q, c = 0;
		bool f = true;
		scanf("%d%d%d%d",&m, &n, &p, &q);
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
		for (int i = 1; i <= p; ++i)
			for (int j = 1; j <= q; ++j) {
				scanf("%d", &b[i][j]);
				if (b[i][j]) {
					++c;
					x[c] = i;
					y[c] = j;
					if (c > 1) {
						x[c] -= x[1];
						y[c] -= y[1];
					}
				}
			}
		x[1] = y[1] = 0;
		for (int i = 1; i <= m; ++ i) {
			for (int j = 1; j <= n; ++j)
				if (a[i][j]) {
					for (int k = 1; k <= c; ++k) {
						if (i + x[k] > m || j + y[k] > n || i + x[k] < 1 || j + y[k] < 1) {
							printf("No\n");
							f = false;
							break;
						}
						if (!a[i + x[k]][j + y[k]]) {
							printf("No\n");
							f = false;
							break;
						}
						a[i + x[k]][j + y[k]] = false;
					}
					if (!f) break;
				}
			if (!f) break;
		}
		if (f) printf("Yes\n");
		--t;
	}
}
