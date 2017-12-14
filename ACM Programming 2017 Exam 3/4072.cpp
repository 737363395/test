#include <cstdlib>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
const int N = 200200;
 
int a[N][3];
bool f[N];
 
int main() {
	int n, m, k, ans = -1;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= n; ++i) f[i] = false;
	for (int i = 1; i <= m; ++i)
		for (int j = 0; j < 3; ++j) scanf("%d", &a[i][j]);
	for (int i = 1; i <= k; ++i) {
		int t;
		scanf("%d", &t);
		f[t] = true;
	}
	for (int i = 1; i <= m; ++i)
		if (f[a[i][0]] ^ f[a[i][1]]) 
			if (a[i][2] < ans || ans == -1) ans = a[i][2];
	printf("%d\n", ans);
	return 0;
	
}
