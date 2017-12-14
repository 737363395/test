#include <cstdlib>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
struct data {
	int x, y, h;
};
 
const int N = 333;
const int M = 666666;
const int D[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
 
int a[N][N];
bool f[N][N][7];
int d[N][N][7];
data q[M];
 
int main() {
	int n, m, l = 1, r = 1;
	scanf("%d%d", &n, &m);
	for (int i = 1;  i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			for (int k = 0; k <= 6; ++k) {
				f[i][j][k] = true;
				d[i][j][k] = N * N;
			}
			if (a[i][j] == 2) {
				q[l] = (data) {i, j, 6};
				d[i][j][6] = 0;
				f[i][j][6] = false;
			}
		}
	while (l <= r) {
		int x = q[l].x, y = q[l].y, h = q[l].h;
		if (h > 1) {
			for (int i = 0; i < 4; ++i) {
				int u = x + D[i][0], v = y + D[i][1], z = a[u][v] == 4 ? 6 : h - 1;
				if (u && u <= n && v && v <= m && a[u][v] && f[u][v][z]) {
					d[u][v][z] = d[x][y][h] + 1;
					if (a[u][v] == 3) {
						printf("%d\n", d[u][v][z]);
						return 0;
					}
					f[u][v][z] = false;
					++r;
					q[r] = (data) {u, v, z};						
				}
			}
		}
		++l;
	}
	printf("-1\n");
	return 0;
}
